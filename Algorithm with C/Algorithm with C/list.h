#pragma once

#include <stdlib.h>

typedef struct ListElmt_ { //연결리스트 항목
	void*				data; 
	struct ListElmt_*	next; //다음을 가리키는 포인터
}ListElmt;

typedef struct List_ {
	int size; //list 크기
	int (*match)(const void* key1, const void* key2); //파생되는 자료형에서 사용될 예정
	void (*destroy)(void* data); // list_init에 전달 될 캡슐화된 제거 함수

	ListElmt	*head; //첫번째 항목을 가리키는 포인터
	ListElmt	*tail; // 마지막 항목을 가리키는 포인터 
} List;

void list_init(List* list, void (*destroy)(void* data));

void list_destroy(List* list);

int list_ins_next(List* list, ListElmt* element, const void* data);

int list_rem_next(List* list, ListElmt* element, void** data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)