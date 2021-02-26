#include <iostream>
#include <vector>
using namespace std;

/*
	# �ð����⵵ ����
	
	O(1) : �ܼ� ���(��� �ð�)
	O(logN) : ����Ž��, N���� �������� ����ؼ� ����
	O(N) : 1�� for��, ���ĵ��� ���� ���̰� N�� �迭���� ���� ���� ���� Ž��
	O(NlogN) : ������, ��������, ������
	O(N^2) : 2�� for��, ��������, ��������, ��������
	O(N^3) : 3�� for��, �÷��̵� ����
	O(2^N) : ũ�Ⱑ N�� ������ �κ� ����, ��ȣ�� �Ű��� N���� ������ ������ �� ���� �� �ִ� ��츦 ���
	O(N!) : ũ�Ⱑ N�� ����, 1���� N���� ���ڸ� ������ �� �ִ� ��� ����� ���

	# 1�ʰ� �ɸ��� �Է��� ũ��
	100,000,000 => 1�� => 1��

	O(1) - 1
	O(logN) - 
	O(N) - 1��
	O(NlogN) - 5�鸸
	O(N^2) - 1��, nC2 = n(n-1)/2 => O(N^2)
	O(N^3) - 500
	O(2^N) - 20
	O(N!) - 10, 11�� 4õ��

	# �پ��� ���̽���
	
	�ϳ��� ������ ����Ͽ� ���� ��� ������ �ݺ��ϴ� ��� O(N)
	�÷����� ���� �̻��� �ݺ��ϴ� ��� O(N/2) -> O(N)
	�� ���� �ٸ� ������ ����Ͽ� �� ���� ���� �÷����� �ݺ��� ��� O(N + M)
	�� ���� ��ø ������ ����Ͽ� ���� �÷����� �ݺ��ϴ� ��� O(N^2)
	�� ���� ��ø ������ ����Ͽ� �� ���� �ٸ� �÷����� �ݺ��ϴ� ��� O(N * M)
	�÷����� �����ϴ� ��� O(NlogN)

	# ���� �˰��� ��

	SortingAlgorithm  |  SpaceComplexity  |  TimeComplexity
	                  |  Worst            |  Best     |  Average  |  Worst    |
	Bubble Sort       |  O(1)             |  O(N)     |  O(N^2)   |  O(N^2)   |
	Selection Sort    |  O(1)             |  O(N^2)   |  O(N^2)   |  O(N^2)   |
	Insertion Sort    |  O(1)             |  O(N)     |  O(N^2)   |  O(N^2)   |
	Heap Sort         |  O(1)             |  O(NlogN) |  O(NlogN) |  O(NlogN) |
	Merge Sort        |  O(N)             |  O(NlogN) |  O(NlogN) |  O(NlogN) |
	Quick Sort        |  O(logN)          |  O(NlogN) |  O(NlogN) |  O(n^2)   |


	# �ڷᱸ�� ��
	
	Data Structure    |           Average Case        |           Worst Case          |
					  |  Search  |  Insert  | Delete  |  Search  |  Insert  | Delete  |
	Array             |  O(N)    |          |         |  O(N)    |          |         |
	Sorted Array      |  O(logN) |  O(N)    |  O(N)   |  O(logN) |  O(N)    |  O(N)   |
	Linked List       |  O(N)    |  O(1)    |  O(1)   |  O(N)    |  O(1)    |  O(1)   |
	DoublyLinked List |  O(N)    |  O(1)    |  O(1)   |  O(N)    |  O(1)    |  O(1)   |
	Stack             |  O(N)    |  O(1)    |  O(1)   |  O(N)    |  O(1)    |  O(1)   |
	Hash table        |  O(1)    |  O(1)    |  O(1)   |  O(N)    |  O(N)    |  O(N)   |
	BinarySearchTree  |  O(logN) |  O(logN) |  O(logN)|  O(N)    |  O(N)    |  O(N)   |
	Red-Black Tree    |  O(logN) |  O(logN) |  O(logN)|  O(logN) |  O(logN) |  O(logN)|
	AVL Tree          |  O(logN) |  O(logN) |  O(logN)|  O(logN) |  O(logN) |  O(logN)|
*/


// O(logN)
while (digit != 0)
{
	digit = digit / 2;
}

// O(N)
for (int n : arr)
{
	cout << n << ' ';
}

// O(N * M)
// v1 ũ�� N, v2 ũ�� M�̶�� �ϸ�,
void f(vector<int> & v1, vector<int> & v2)
{
	for (int i = 0; i < v1.size(); i++)
		for (int j = 0; j < v2.size(); j++)
			cout << i + j << ' ';
}


// O(a/b)
int div(int a, int b)
{
	int count = 0;
	int sum = b;
	while (sum <= a)
	{
		sum += b;
		count++;
	}
	return count;
}

// O(sqrt(n))
int sqrt(int n)
{
	for (int g = 1; g * g <= n; g++)
	{
		if (g * g == n) return g;
	}
	return -1;
}

/*
	if a binary search tree is not balanced,
	how long might it take worse case to find an element in it?
	O(N)

	You are looking for specific value in a binary tree,
	but the tree is not a binary search tree.
	what is the time complexity of this?
	O(N)
*/


// O(N)
int* appendToNew(int* arr, int len, int value)
{
	int* bigger = new int[len + 1];
	for (int i = 0; i < len; i++) bigger[i] = arr[i];
	bigger[len] = value;
	return bigger;
}

// O(N^2)
int* copyArray(int* array)
{
	int* copy;
	for (int i = 0; i < array.size(); i++)
	{
		copy = appendToNew(copy, array[i]);
	}
	return copy;
}


// O(logN)
int sumDigits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

// O(blogb + alogb)
int intersection(vector<int>& a, vector<int>& b)
{
	mergesort(b);
	int intersect = 0;
	for (int x : a)
	{
		if (binarySearch(b, x) >= 0)
		{
			intersect++;
		}
	}
	return intersect;
}

// O(2^N)
int f(int n, int r)
{
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	return f(n - 1, r) + f(n - 2, r);
}