// https://yabmoons.tistory.com/303
// ��� ������ ���� �߿��� �� ����. Ȯ���� �� ������ �������..
// �׻� �ڵ�� ���ظ� �ϰ��� �ۼ��ϴ� ���� ���� ����. �׷��� ������ �� �ٵ� ������ ����
// BackTracking + BruteForce
#include <iostream>

#define MAX 10
using namespace std;

struct STATE
{
	int Prev;              // ���� ĭ
	int Next;              // �̵��Ϸ��� ĭ
	int Start_Circle;      // ������ �Ķ����� ��ȣ (1,2,3 �� �ϳ�)
	bool Select_Circle;    // �̹� ���������� �Ķ��� ���� ��ȣ�� �����Ǿ������� ���� �����Ǵ�
	bool Finish;           // �̹� ���������� ���� �������� �����Ͽ������� ���� ���� �Ǵ�
};

struct YUT
{
	int Blue_Circle;       // ���� �ѹ��̶� ������ �Ķ��� ���� ��ȣ
	int Pos;               // ���� ����
	int Score;             // ���� ����
	bool Finish;           // ���� �������� �����ߴ����� ���� ����
};

int answer;
int Command[MAX];
int MoveNum[4];            // �� ��� ��, �������� �ϴ� �ִ� ĭ��
int MAP_Score[4][30];      // ���� ��
bool Visit[4][30];         // �̹� �ٸ� ���� �ִ��� ������ �Ǵ��ϱ� ���� �迭
bool Special_Point[4][30]; // Ư���� �� (��� ��ΰ� ��ġ�� ĭ���� �ǹ�)

YUT Yut[4];

void Setting()
{
	/* �⺻ ���� �۾� */
	/*
		1. �� ��� �� �������� �ϴ� �ִ� ĭ���� ��������.
		2. Ư���� ������ üũ����.
		3. ���� �� ������.
	*/
	MoveNum[0] = 21;
	MoveNum[1] = 13;
	MoveNum[2] = 17;
	MoveNum[3] = 23;

	Special_Point[1][9] = Special_Point[1][10] = Special_Point[1][11] = Special_Point[1][12] = true;
	Special_Point[2][13] = Special_Point[2][14] = Special_Point[2][15] = Special_Point[2][16] = true;
	Special_Point[3][19] = Special_Point[3][20] = Special_Point[3][21] = Special_Point[3][22] = true;
	Special_Point[0][1] = Special_Point[0][2] = Special_Point[0][3] = Special_Point[0][4] = Special_Point[0][5] = Special_Point[0][20] = true;

	for (int i = 1; i <= 20; i++) MAP_Score[0][i] = 2 * i;
	MAP_Score[1][6] = 13; MAP_Score[1][7] = 16; MAP_Score[1][8] = 19; MAP_Score[1][9] = 25;
	MAP_Score[1][10] = 30; MAP_Score[1][11] = 35; MAP_Score[1][12] = 40;
	MAP_Score[2][11] = 22; MAP_Score[2][12] = 24; MAP_Score[2][13] = 25; MAP_Score[2][14] = 30;
	MAP_Score[2][15] = 35; MAP_Score[2][16] = 40;
	MAP_Score[3][16] = 28; MAP_Score[3][17] = 27; MAP_Score[3][18] = 26; MAP_Score[3][19] = 25;
	MAP_Score[3][20] = 30; MAP_Score[3][21] = 35; MAP_Score[3][22] = 40;

	for (int i = 1; i <= 5; i++) MAP_Score[1][i] = MAP_Score[0][i];
	for (int i = 1; i <= 10; i++) MAP_Score[2][i] = MAP_Score[0][i];
	for (int i = 1; i <= 15; i++) MAP_Score[3][i] = MAP_Score[0][i];
}

void Input()
{
	for (int i = 0; i < 10; i++) cin >> Command[i];
}

STATE GetState(int idx, int c_idx)
{
	/* ������ ���������� ���ϴ� ���� ���¸� �޾ƿ��� �Լ� */


	int Prev = Yut[idx].Pos;                   // ���� ���� �ִ� ĭ
	int Next = Yut[idx].Pos + Command[c_idx];  // ���� �̵��Ϸ��� ĭ
	int Start_Circle = Yut[idx].Blue_Circle;   // ������ ������ �Ķ��� ���� ��ȣ
	bool Select_Circle = false;                // �̹� ���� ���������� ���� �Ķ��� ���� �����Ǿ������� ���� ����
	bool Finish = false;                       // �̹� ���� ���������� ���� �������� �����ߴ����� ���� ����

	if (Start_Circle == 0)        //  ���� ������ �Ķ��� ���� ���� ��쿡��
	{
		if (Prev == 5 || Prev == 10 || Prev == 15)
		{
			Select_Circle = true; // �̹� ���� ���������� �Ķ��� ���� ������.
			Start_Circle = Prev / 5;
		}
	}

	if (Next >= MoveNum[Start_Circle]) Finish = true;    // �������� �����ߴٸ� üũ

	return { Prev, Next, Start_Circle, Select_Circle, Finish };
}

bool Check_Special_Point(int Circle, int Pos)
{
	/* Ư���� ���� �ٸ� ���� �����ϴ��� �Ǵ��ϴ� �Լ� */

	if (Circle == 0)
	{
		/* ���� �̵��Ϸ��� ���� �Ķ��� ������ ������ ���� ���� ��� */
		/* '40'���� �����Ǿ��ִ� ĭ�� ������ ���� �ִ��� �Ǵ��� �ָ� �ȴ�. */
		/* '40'���� �ִ� ĭ��, ������, �Ķ���, �ʷϻ�, ��Ȳ�� ��� ��ġ�� ����̱� �����̴�. */

		if (Pos == 20) // 40�� ĭ�� �����ߴµ�
		{
			if (Visit[1][12] == true || Visit[2][16] == true || Visit[3][22] == true) return false; // �ϳ��� ���� �ִٸ� ����
		}
		else
		{
			if (Visit[0][Pos] == true) return false;
		}
	}
	else if (Circle == 1)
	{
		/* ���� ����, 1�� �Ķ� ������ �����ؼ� �����̰� �ִ� ��� */
		/* �Ķ��� / ��Ȳ�� ��ΰ� ��ġ�� '25', '30', '35', '40'�� üũ����� �Ѵ�.*/

		if (Visit[2][Pos + 4] == true || Visit[3][Pos + 10] == true) return false;

		if (Pos == 12) // 40�� ĭ�� �����ߴµ�
		{
			if (Visit[0][20] == true) return false;
		}
	}
	else if (Circle == 2)
	{
		if (Visit[1][Pos - 4] == true || Visit[3][Pos + 6] == true) return false;
		if (Pos == 16)
		{
			if (Visit[0][20] == true) return false;
		}
	}
	else if (Circle == 3)
	{
		if (Visit[1][Pos - 10] == true || Visit[2][Pos - 6] == true) return false;
		if(Pos == 22)
		{
			if (Visit[0][20] == true) return false;
	    }
	}
	return true;
}

bool Check_Visit(STATE S, int idx)
{
	/* ���� ���� ������ �� �ִ����� �Ǵ����ִ� �Լ� */
	/* �Ǵ��� ��� �� ��
		1. �����̷��� ��ǥ�� Ư���� ������?
			- Ư���� ���̶�� �ٸ� ��θ� ���ؼ� �ش� ��ǥ�� �ִ� ��鵵 check������.
		2. �����̷��� ��ǥ�� �ٸ� ���� �����ϴ���?
	*/
	if (Special_Point[S.Start_Circle][S.Next] == true)
	{
		if (Check_Special_Point(S.Start_Circle, S.Next) == false) return false;
	}

	if (Visit[S.Start_Circle][S.Next] == true) return false;
	return true;
}

void MakeState(STATE S, int idx, bool T)
{
	/* �湮 üũ�� �ϰ�, ������ ���� �ű�� �Լ� */
	/* T = true �� ���, ���� */
	/* T = false �� ���, ���� ��� (��Ʈ��ŷ) */

	if (T == true)
	{
		if (S.Finish == true)
		{
			/* ���� ���� ���������� ���� �������� �����ߴٸ�? */
			Visit[S.Start_Circle][S.Prev] = false;  // ���� ��ǥ �湮 üũ ����
			Yut[idx].Pos = S.Next;                  // ���� ���� ��ǥ ����
			Yut[idx].Finish = true;                 // �������� ǥ��
		}
		else
		{
			/* ���� ���� ���������� ���� �������� ���������� ���� ���� */
			if (S.Select_Circle == true)
			{
				/* ���� ���� ���������� �Ķ����� ��ȣ�� ���� �Ǿ��ٸ�? */

				Yut[idx].Blue_Circle = S.Start_Circle;  // ���� �Ķ� ���� ��ȣ�� ����
				Visit[0][S.Prev] = false;               // ���� ��ǥ �湮 üũ ����

				/* �̹� �Ͽ� �Ķ����� ��ȣ�� �����Ǿ��� = �������� �Ķ����� �������� ���� ���¿���.
				   ��, ������ ��ǥ üũ ������ �Ķ����� �������� ���� Visit[0][S.Prve]�� ���ش�.
				*/
			}
			else
			{
				/* ���� ���� ���������� �Ķ����� ��ȣ�� �������� �ʾҴ�.
				   Ȥ��, �̹� ���������� ����, �ƴϸ� ���� �������� ���� ���ϼ��� �ִ�. */

				Visit[Yut[idx].Blue_Circle][S.Prev] = false; // ���� ��ǥ �湮 üũ ����
			}
			Visit[Yut[idx].Blue_Circle][S.Next] = true; // �湮 üũ
			Yut[idx].Pos = S.Next;                      // ��ǥ ����
			Yut[idx].Score = Yut[idx].Score + MAP_Score[Yut[idx].Blue_Circle][S.Next]; // ���� ����
		}
	}
	else
	{
		/* ���� ����ϴ� ���� */
		if (S.Finish == true)
		{
			/* �̹� �Ͽ� ���� �������� �����ߴٸ�? */
			Visit[S.Start_Circle][S.Prev] = true;  // ������ ��ǥ �湮 üũ
			Yut[idx].Pos = S.Prev;                 // ��ǥ�� �ǵ�����
			Yut[idx].Finish = false;               // ����ǥ�� ����
		}
		else
		{
			if (S.Select_Circle == true)
			{
				/* �̹� ������ ���ؼ� �Ķ��� ���� ���� �Ǿ��µ�, �̸� ��������Ѵ�. */
				Visit[0][S.Prev] = true;
				Visit[Yut[idx].Blue_Circle][S.Next] = false;
				Yut[idx].Pos = S.Prev;
				Yut[idx].Score = Yut[idx].Score - MAP_Score[Yut[idx].Blue_Circle][S.Next];
				Yut[idx].Blue_Circle = 0; // ������ �Ķ����� ��ȣ �ٽ� 0���� ����.
			}
			else
			{
				Visit[Yut[idx].Blue_Circle][S.Prev] = true;
				Visit[Yut[idx].Blue_Circle][S.Next] = false;
				Yut[idx].Pos = S.Prev;
				Yut[idx].Score = Yut[idx].Score - MAP_Score[Yut[idx].Blue_Circle][S.Next];
			}
		}
	}

}

void DFS(int cnt)
{
	if (cnt == 10)
	{
		int temp = 0;
		for (int i = 0; i < 4; i++) temp = temp + Yut[i].Score;

		if (answer < temp) answer = temp;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (Yut[i].Finish == true) continue;            // �ش� ���� �������� �����ߴ���?
		STATE State = GetState(i, cnt);                 // �ƴ϶��, ���� ���¸� ��������,
		if (Check_Visit(State, i) == false) continue;   // �� ���¿��� ������ �� �ִ��� üũ

		MakeState(State, i, true);                      // �����ϴٸ� ��������.
		DFS(cnt + 1);                                   // ���� �� ����
		MakeState(State, i, false);                     // �ǵ�����.
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	Setting();
	Input();
	DFS(0);
	cout << answer << '\n';
	return 0;
}