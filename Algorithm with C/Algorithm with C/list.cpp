#include "list.h"
#include <cstring>
#include <cstdlib>


void list_init(List* list, void (*destroy) (void* data))
{
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

int list_ins_next(List* list, ListElmt* element, const void* data)
{
	ListElmt* new_element;

	if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL) {
		return -1;
	}

	new_element->data = (void*)data;

	if (element == NULL) {
		if (list_size(list) == 0) {
			list->tail == new_element;
		}

		new_element->next = list->head;
		list->head = new_element;

	}
	else {

		if (element->next == NULL) {
			list->tail = new_element;
		}

		new_element->next = element->next;
		element->next = new_element;
	}
	list->size++;

	return 0;
}

int list_rem_next(List* list, ListElmt* element, const void** data)
{
	return 0;
}