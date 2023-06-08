#include<iostream>
#include<algorithm>
using namespace std;

int a[11] = {0, 38, 65, 97, 76, 13, 27, 49, 55, 4,2};


void adjust_sort(int a[], int n, int k) {
	a[0]=a[k];//���Ҫ������k��λ��
	for(int i=2*k;i<=n;i*=2){
		if(i<n&&a[i]<a[i+1])i++;//��������
		if(a[0]>=a[i])break;
		else{
			a[k]=a[i];
			k=i;
		}
	}
	a[k]=a[0];//���λ�þ�����ε�	
};

void build_sort(int a[], int n) {
	for (int i = n / 2; i >=1; i--) {
		adjust_sort(a,n,i);
	}
}


void heap_sort(int a[], int n) {
	build_sort(a, n);
	for (int i = n; i > 1; i--) { //���һ��Ԫ�ز��õ���
		swap(a[1], a[i]);//ÿ�ΰѶ�ͷ����ĩβ
		adjust_sort(a, i-1, 1);//������ ��С-1 ����ͷ����
	}
}
void show(int a[], int n) {
	for (int i = 1; i < n; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	heap_sort(a, 10);
	show(a, 11);

}
