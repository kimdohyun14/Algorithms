// ��ó : �ڵ� ���ͺ� ���� �м�

// �������� ��쿡 ���� Big-O ǥ����� Ȯ������.

// ����� ȣ�� : O(2^N)
int f(int n)
{
	if (n <= 1)
		return 1;
	return f(n - 1) + f(n - 1);
}

// �迭�� ���� �� : O(N)
// �� �� �е�, �� �� �е� Big-O���� ������ ���� ����.
void foo(int array[])
{
	int sum = 0;
	int product = 1;

	for (int i = 0; i < array.length; i++)
		sum += array[i];

	for (int i = 0; i < array.length; i++)
		product *= array[i];
}

// 2�� ���� : O(N^2)
void printUnorderedPairs(int array[])
{
	for (int i = 0; i < array.length; i++)
		for (int j = i + 1; j < array.length; j++)
			printf("%d, %d ", array[i], array[j]);
}

// 2�� ������ �߰����� ������ ����? : O(N^2)
void printUnorderedPairs(int array[])
{
	for (int i = 0; i < array.length; i++)
		for (int j = i + 1; j < array.length; j++)
			/* if ... O(1) �ð��� �ɸ��� �۾� ...  */
}

// 2�� ���������� �Ǽ��ϴ� ��� : O(AB)
// �� �迭�� ũ�⸦ ��� ����ؾ� �Ѵ�.
void printUnorderedPairs(int A[], int B[])
{
	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < B.size(); j++)
			/* ���� */
}