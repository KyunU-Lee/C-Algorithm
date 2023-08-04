#include "list.h"
#include <cstring>
#include <cstdlib>


void list_init(List* list, void (*destroy) (void* data)) 
{
	//연결 리스트를 초기화 함 
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

int list_ins_next(List* list, ListElmt* element, const void* data) // element NULL 새항목 추가
{
	ListElmt* new_element;
	//새로운 element 메모리 생성
	if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL) {
		return -1;
	}
	//데이터 삽입
	new_element->data = (void*)data;
	//비어있는 List인가? (head에 삽입)
	if (element == NULL) { //element에 NULL(항목 추가)을 입력하면 head에 데이터를 삽입하라. 
		if (list_size(list) == 0) {//첫번째 데이터 라면 tail도 [element][next]
			list->tail = new_element;
		}
		//다음을 가리키는 포인터가 head를 가리킴
		new_element->next = list->head;
		//head에 새로운 데이터가 입력됨
		list->head = new_element;

	}
	else {
		// tail 인가?
		if (element->next == NULL) { //새항목 추가 인가?
			list->tail = new_element;
		}
		//기존의 next 포인터를 새로 만들어진 포인터로 바꿔줌
		new_element->next = element->next; //NULL을 가리킴? 이해잘안됨 
		element->next = new_element;
	}
	list->size++;

	return 0;
}

//다음 리스트 제거
int list_rem_next(List* list, ListElmt* element, void** data) // element NULL -> 삭제
{
	// 임시 element
	ListElmt* old_element;
	//빈리스트 삭제 X
	if (list_size(list) == 0)
		return -1;
	//Head 삭제 
	if (element == NULL) { //삭제 명령
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;

		if (list_size(list) == 0)
			list->tail = NULL;
	}
	else
	{
		if (element->next == NULL) { // 삭제가 아니라면
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