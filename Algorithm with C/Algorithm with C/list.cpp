#include "list.h"
#include <cstring>
#include <cstdlib>


void list_init(List* list, void (*destroy) (void* data)) 
{
	//���� ����Ʈ�� �ʱ�ȭ �� 
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

void list_destroy(List* list)
{
	void* data;

	while (list_size(list) > 0)
	{
		if (list_rem_next(list, NULL, (void**)&data) == 0 && list->destroy != NULL) {
			list->destroy(data);
		}

	}

	memset(list, 0, sizeof(List));

}

int list_ins_next(List* list, ListElmt* element, const void* data) // element NULL ���׸� �߰�
{
	ListElmt* new_element;
	//���ο� element �޸� ����
	if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL) {
		return -1;
	}
	//������ ����
	new_element->data = (void*)data;
	//����ִ� List�ΰ�? (head�� ����)
	if (element == NULL) { //element�� NULL(�׸� �߰�)�� �Է��ϸ� head�� �����͸� �����϶�. 
		if (list_size(list) == 0) {//ù��° ������ ��� tail�� [element][next]
			list->tail = new_element;
		}
		//������ ����Ű�� �����Ͱ� head�� ����Ŵ
		new_element->next = list->head;
		//head�� ���ο� �����Ͱ� �Էµ�
		list->head = new_element;

	}
	else {
		// tail �ΰ�?
		if (element->next == NULL) { //���׸� �߰� �ΰ�?
			list->tail = new_element;
		}
		//������ next �����͸� ���� ������� �����ͷ� �ٲ���
		new_element->next = element->next; //NULL�� ����Ŵ? �����߾ȵ� 
		element->next = new_element;
	}
	list->size++;

	return 0;
}

//���� ����Ʈ ����
int list_rem_next(List* list, ListElmt* element, void** data) // element NULL -> ����
{
	// �ӽ� element
	ListElmt* old_element;
	//�󸮽�Ʈ ���� X
	if (list_size(list) == 0)
		return -1;
	//Head ���� 
	if (element == NULL) { //���� ���
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;

		if (list_size(list) == 0)
			list->tail = NULL;
	}
	else
	{
		if (element->next == NULL) { // ������ �ƴ϶��
			return -1;
		}

		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;

		if (element->next == NULL)
			list->tail = element;
	}

	free(old_element);

	list->size--;

	return 0;
}