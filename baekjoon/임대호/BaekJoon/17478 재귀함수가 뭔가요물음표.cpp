//#include <iostream>
//
//using namespace std;
//
//int n;
//
//void Func(int count)
//{
//	string temp = "";
//	for (int i = 0; i < 4 * (n - count); i++)
//	{
//		temp += '_';
//	}
//
//	cout << temp << "\"����Լ��� ������?\"\n";
//	if (count <= 0)
//	{
//		cout << temp << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
//		cout << temp << "��� �亯�Ͽ���.\n";
//		return;
//	}
//	cout << temp << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
//	cout << temp << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
//	cout << temp << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
//
//	Func(count - 1);
//
//	cout << temp << "��� �亯�Ͽ���.\n";
//}
//
//int main()
//{
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	ios::sync_with_stdio(false);
//
//	cin >> n;
//
//	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
//	Func(n);
//
//	return 0;
//}