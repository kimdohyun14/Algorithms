#include <iostream>
#include <set>
using namespace std;

/*
	# set�� Ư¡��
	1. ���ڵ� ���ڵ� �ߺ��� ���ش�.
	2. �����ϴ� ������ ������� ���ĵǼ� �Էµȴ�.
	3. balanced tree (R-B Tree)

	# set �뷮
	empty() : ����ִٸ� true, �ƴϸ� false
	size() : set ����� ������ ��
	max_size() : set�� ���� �� �ִ� �ִ� ũ��

	# set ����,����
	insert() : set�� ����
	erase() : set�� ����� ��� ����
	swap() : set1, set2 ����
	clear() : ��ҵ� ���� ����
	emplace() : move()�� ����� ��ü�� ����
	emplace_hint() : ���Ե� ��ġ�� ���� ��Ʈ�� ���� ����

	# set ��ɵ�
	find() : ã�� ���� �ִٸ� �ش� ��ġ�� iterator�� ��ȯ, �ƴϸ� end() ��ȯ
	count() : set�� ����� ��� ���� ��ȯ
	lower_bound() : set ����� ��ġ�� ���� iterator�� ��ȯ, �� ���� ���ų� �̻��� �κ�
	upper_bound() : set ����� ��ġ�� ���� iterator�� ��ȯ, �� ���� �ʰ��ϴ� �κ�
	equal_range() : �ش� ��ҿ� ���� ���� iterator�� ��ȯ

	# set �ݺ���
	begin() : ���۵Ǵ� �ּ�
	end() : ������ �� �ּ�
	rbegin() : ������ �κ��� ���� �ּ�
	rend() : ù��° �κ��� ������ �ּ�
	cbegin() : begin()�� ���������� const�� ����
    cend() : end()�� ���������� const�� ����
	crbegin() : rbegin()�� ���������� const�� ����
    crend() : rend()�� ���������� const�� ����
*/

int main()
{
	set<int> s{ 1,2,3,4,5 };

	s.insert(3); // 1 2 3 4 5
	s.insert(5); // 1 2 3 4 5
	s.insert(7); // 1 2 3 4 5 7
	s.insert(-1);// -1 1 2 3 4 5 7

	if (s.find(7) != s.end())
		cout << "7 found!\n";
	else
		cout << "7 not found!\n";

	cout << "s.empty() : " << s.empty() << endl;
	cout << "s.size() : " << s.size() << endl;
	cout << "s.max_size() : " << s.max_size() << endl << endl;

	set<int> s2 = { 1,2,3,4,5,6,7,8,9,10 };
	pair<set<int>::iterator, set<int>::iterator> iter = s2.equal_range(4);
	cout << "s2.equal_range(4) : " << *iter.first << ' ' << *iter.second << endl;

	set<int>::iterator lower_iter = s2.lower_bound(3);
	set<int>::iterator upper_iter = s2.upper_bound(3);
	cout << "lower_iter : " << *lower_iter << endl;
	cout << "upper_iter : " << *upper_iter << endl;

	// 3 ~ 7 ����
	lower_iter = s2.lower_bound(3);
	upper_iter = s2.upper_bound(7);
	s2.erase(lower_iter, upper_iter);
	for (int n : s2) cout << n << ' ';
	cout << endl << endl;

	set<int> s3;

	s3.emplace(10);
	s3.emplace(20);
	s3.emplace(-1);
	s3.emplace(-5);
	s3.emplace(7);

	set<int>::iterator s3_iter = s3.emplace_hint(s3.end(), 21); // ���� �ӵ� ����
	s3.emplace_hint(s3_iter, 1); // ���� �ӵ� ����
	for (int n : s3) cout << n << ' ';
	cout << endl << endl;

	// insert�� emplace ��ȯ���� pair<iterator, bool>
	// pair.first ������ ��ġ�� ���� iterator
	// pair.second ���� ���� ���ο� ���� bool
	set<int> s4;
	pair<set<int>::iterator, bool> chk = s4.insert(10);
	if (chk.second)
		cout << "10 insert success!\n";
	else
		cout << "10 insert failure!\n";

	set<pair<int, int>> s5;
	s5.insert({ 2,3 });
	s5.insert({ 1,5 });
	s5.insert({ 1,2 });
	s5.emplace(5, 6);
	for (auto n : s5) cout << n.first << ' ' << n.second << endl;

	return 0;
}