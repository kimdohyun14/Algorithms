// stack 컨테이너를 이용한 정수 입출력
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	stack<int, vector<int>> st; // vector 컨테이너를 이용한 stack 컨테이너 생성

	st.push(10); // 데이터 추가
	st.push(20);
	st.push(30);

	cout << st.top() << endl; // 데이터 출력
	st.pop(); // 데이터 삭제
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();

	if (st.empty()) // 스택이 비어있는지 확인
		cout << "stack에 데이터 없음" << endl;

	return 0;
}