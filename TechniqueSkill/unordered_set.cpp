#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set<string> s;

	s.insert("abc");
	s.insert("def");
	s.insert("ghi");
	s.insert("jkl");

	// string(input) -> hash function -> hash value
	cout << "abc: " << hash<string>{}("abc") << endl;
	cout << "def: " << hash<string>{}("def") << endl;
	cout << "ghi: " << hash<string>{}("ghi") << endl;
	cout << "jkl: " << hash<string>{}("jkl") << endl << endl;

	// hash value % bucket_count -> index(hash table mapping)
	cout << "bucket count : " << s.bucket_count() << endl;
	cout << "abc bucket : " << s.bucket("abc") << endl;
	cout << "def bucket : " << s.bucket("def") << endl;
	cout << "ghi bucket : " << s.bucket("ghi") << endl;
	cout << "jkl bucket : " << s.bucket("jkl") << endl << endl;

	// �� ���� input�� ������, rehashing�� �߻��Ѵ�.
	// rehashing �� O(N)�� �Ҹ�ǹǷ�,
	// �̸� �����ϰ��� �� �� �̸� �Ҵ����ִ� reserve �� ����Ѵ�.
	s.insert("dasq");
	s.insert("dasdawq");
	s.insert("rdewq");
	s.insert("vkbas");
	s.insert("treq");
	s.insert("gfoas");
	s.insert("bdea");
	s.insert("dela");
	s.insert("jgela");
	cout << "bucket count : " << s.bucket_count() << endl;
	return 0;
}