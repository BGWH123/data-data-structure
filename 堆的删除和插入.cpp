#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
#include<random>
using namespace std;

void show(vector<int>&v) {
	for (int i = 1; i < v.size(); i++)cout << v[i] << " ";
	cout << endl;
}

void adjust_heap(vector<int>&v, int n, int k) {
	v[0] = v[k];
	for (int i = k * 2; i <= n; i *= 2) {
		if (i < n && v[i] < v[i + 1])i++;
		if (v[i] <= v[0])break;
		else {
			v[k] = v[i];
			k = i;
		}
		v[k] = v[0];
	}
}

void build_heap(vector<int>&v) {
	int n = v.size() - 1;
	for (int i = n / 2; i >= 1; i--) {
		adjust_heap(v, n, i);
	}
}

void heap(vector<int>&v) {
	int n = v.size() - 1;
	build_heap(v);
	for (int i = n; i > 1; i--) {
		swap(v[1], v[i]);
		adjust_heap(v, i - 1, 1);
	}
	show(v);
}
void add_heap(vector<int>&v, int k) {
	v.emplace_back(k);
	int n = v.size() - 1; //���Ԫ��λ��
	while (n > 1 && (v[n / 2] < v[n])) {

		swap(v[n / 2], v[n]);
		n /= 2;
	}
	show(v);

}
void delete_heap(vector<int>&v, int pos) {
	//���λ�ú����һ��λ�ý���
	swap(v[pos], v[v.size() - 1]);
	v.pop_back();//ɾ�����һ��Ԫ��
	//�����λ�õ���
	adjust_heap(v, v.size() - 1, pos);
	show(v);
}


int main() {
	vector<int>a;
	a.emplace_back(0);
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		a.emplace_back(rand() % 20);
	}
	show(a);
	cout << endl;
	cout << "������˵ģ�" << endl;
	heap(a);
	cout << "���Ԫ�أ�" << endl;
	a.clear();
	a.emplace_back(0);
	for (int i = 0; i < 10; i++) {
		a.emplace_back(rand() % 20);
	}
	cout << "�µģ�" << endl;
	show(a);
	cout << "���Ѻ�" << endl;
	build_heap(a);
	show(a);
	int t = rand() % 20;
	cout << "����Ԫ�أ�" << t << endl;
	add_heap(a, t);
	cout << "ɾ���ڶ���Ԫ�غ�Ķ�" << t << endl;
	delete_heap(a, 2);

}
