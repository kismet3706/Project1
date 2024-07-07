#include <stdio.h>	
#include <string.h>
#include <stdlib.h>	//#define EXIT_SUCCESS 0

typedef enum {
	PLAYER_ATTACK,
	PLAYER_MOVE,
	//.....
	EVENT_COUNT	//记录事件的总数，写在最后就刚好等于前面的总和；（妙处）
}GameEventType;

//
typedef  void (*EventHandler)(const char* playerName);

//
EventHandler eventHanders[EVENT_COUNT];		//函数指针的数组

//
void registerEventHander(GameEventType eventType, EventHandler handler);
void dispatchEvent(GameEventType eventType, const char* playerName);	//派遣事件

//
void handlePlayerAttack(const char* playerName);
void handlePlayerMove(const char* playerName);

int main(void)
{
	registerEventHander(PLAYER_ATTACK, handlePlayerAttack);
	registerEventHander(PLAYER_MOVE, handlePlayerMove);

	//
	dispatchEvent(PLAYER_ATTACK, "Kismet");
	dispatchEvent(PLAYER_MOVE, "Kismet");

	return EXIT_SUCCESS;
	//#define EXIT_SUCCESS 0----#include <stdlib.h>
}

void registerEventHander(GameEventType eventType, EventHandler handler) {
	if (eventType >= 0 && eventType < EVENT_COUNT) {
		eventHanders[eventType] = handler;	//这里就是event ->Function 在映射
	}
	else {
		fprintf(stderr, "Invalid eventType: %d\n", eventType);
	}
}

void dispatchEvent(GameEventType eventType, const char* playerName) {
	if (eventHanders[eventType] != NULL) {
		eventHanders[eventType](playerName);	//这里就是void (*EventHandler)(const char* playerName);
	}
}

void handlePlayerAttack(const char* playerName) {
	printf("%s attacks!\n", playerName);
}

void handlePlayerMove(const char* playerName) {
	printf("%s moves!\n", playerName);
}