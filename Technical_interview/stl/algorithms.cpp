#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	int arr1[100000];
	vector<int> arr2(100000);
	int n = 100000;

	// sort
	// ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �ѱ��.
	sort(arr1, arr1 + n);
	sort(arr2.begin(), arr2.end());
	// �� �Լ��� ���� ���� �Ѱ��� �� �ִ�.
	sort(arr1, arr1 + n, cmp);


	// stable_sort
	stable_sort(arr1, arr1 + n);

	// lower_bound
	// ù ������ �ּҿ� ������ ������ ���� �ּҿ� ���� ���Ҹ� �ѱ��.
	// ���� ���� ���ҵ��� ���ĵǾ� �־�� �Ѵ�.
	// ���� ���� �ش� ������ �ּҰ��̰�, ���ٸ� arr1+n�� �����Ѵ�.
	// �Ǵ� arr2.end()�� �����Ѵ�.
	int idx = lower_bound(arr1, arr1 + n, 42) - arr1;
	printf("%d\n", idx);

	// upper_bound
	// ������ ����.
	vector<int>::iterator it = upper_bound(arr2.begin(), arr2.end(), 54);
	if (it != arr2.end())
		printf("%d\n", *it);

	// max_element
	// ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �ѱ��.
	// ���� ���� �ִ밪�� ������ ������ �ּҸ� �����Ѵ�.
	printf("max : %d\n", *max_element(arr1, arr1 + n));

	// min_element
	// ������ ����.
	printf("min : %d\n", *min_element(arr2.begin(), arr2.end()));

	// unique
	// ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �ѱ��.
	// ���� ���� �ߺ��� ���Ҹ� ������ ���κ����� �о��ְ� ������ ������ ���� �ּҸ� �����Ѵ�.
	// ���� ���� ���ҵ��� ���ĵǾ� �־�� �Ѵ�.
	// ���� erase�� �Բ� �ߺ��� ���Ҹ� �����ϴ� ������� ����Ѵ�.
	// �Ʒ��� ����� �ߺ��� ���Ҹ� �����ϴ� ����̴�.
	arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

	// next_permutation
	// ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �ѱ��.
	// ���� ���� ���ҵ��� ���� ������ �����ϰ� true�� �����Ѵ�.
	// ���� ������ ���ٸ� false�� �����Ѵ�.
	// ���� ���� ���ҵ��� ���ĵǾ� �־���Ѵ�.
	// ���� do ~ while���� �̿��Ѵ�.

	// next_permutation : O(N)
	// prev_permutation : O(N)
	// all_permutation  : O(N * N!)
	// �Ϲ������� N = 10�� �Ѿ�� �ð��ʰ��� ���.
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;

	do
	{
		for (int i = 0; i < 10; i++)
			printf("%d ", arr[i]);
		printf("\n");
	} while (next_permutation(arr, arr + 10));
	return 0;
}