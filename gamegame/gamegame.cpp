#include <bangtal.h>
//scene1을 선언한다
SceneID scene1;
//paeg를 선언한다
ObjectID page, hint;
//배열 기기
ObjectID right[7];
ObjectID left[7];

bool checked[7];


//            깃발, 소라,샴푸,사과,수박, 아이스크림, 모자
int leftX[7] =  { 580, 175, 170, 260, 270, 500, 390 };			
int rightX[7] = { 1210, 805, 800, 890, 900, 1130, 1020 };	
int Y[7] =      { 40, 75, 274, 255, 200, 175, 450 };	
//범위
int radius[7] = { 54, 50, 60,30, 30, 50, 50 };				


//사각형 범위내에 있는 함수 만들기
bool checkIn(int x, int y, int cx, int cy, int r) {
	return (x > cx - r && x<cx + r && y>cy - r && y < cy + r);
}





//마우스 이벤트 콜백함수 만들기
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == page) {
		//wrong을 true로 초기화
		bool wrong = true;


		for (int i = 0; i < 7; i++) {
			if (checkIn(x, y, leftX[i], Y[i], radius[i]) || checkIn(x, y, rightX[i], Y[i], radius[i])) {
				showObject(left[i]);
				showObject(right[i]);
				//찾은 경우에 checked[i]를 true로 변경
				checked[i] = true;
				wrong = false;
			}
		}

		if (wrong) {
			endGame();
		}
		// 새로 찾은 경우에 모두 찾았으면 게임종료
		else {
			// 모두 찾았는가를 저장하는 변수를 선언하기
			bool completed = true;

			// 7개 중에서 하나라도 찾지 못한 것이 있으면 completed = false로 변경한다.
			// i는 0부터 7보다 작을 때까지 i를 1씩 증가시켜주는 반복문
			for (int i = 0; i < 7; i++) {
				// checked[i]가 false이면 completed를 false로 변경한다.
				if (checked[i] == false) {
					completed = false;
				}
			}

			
			}
		}
	}


	


int main() {
	//마우스 이벤트를 처리할 콜백함수
	setMouseCallback(mouseCallback);

	//장면을 생성한다
	scene1 = createScene("틀린그림찾기", "page.png");

	//배경이미지를 object로 생성한다.
	page = createObject("page.png");
	locateObject(page, scene1, 0, 0);
	showObject(page);



	for (int i = 0; i < 7; i++) {
		left[i] = createObject("check.png");
		locateObject(left[i], scene1, leftX[i] - 25, Y[i] + 27);	  

		right[i] = createObject("check.png");
		locateObject(right[i], scene1, rightX[i] -25, Y[i] + 27); 
	}




	//메시지를 보여준다
	showMessage("7개의 틀린그림 찾기 게임입니다");
	
	startGame(scene1);
}