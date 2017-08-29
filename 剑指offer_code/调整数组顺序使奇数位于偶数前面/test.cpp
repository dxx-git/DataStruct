#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
void reOrderArray(vector<int> &array) {
	int two = 0;//ż�����ݵ��±�
	int one = 0;//�������ݵ��±�
	int size = array.size();
	int start = 0;
	int end = 0;

	while(two < size)
	{
		while(one == size)
		{
			++two;
			if(two == size-1)
				return;
			swap(array[one-1],array[two]);
		}
		while(two < size && array[two]%2 == 1)//��ż�����±�
		{
			++one;
			++two;
		}
		while(one < size && array[one]%2 == 0)//�������±�
			++one;
		if(one < size)
		{
			swap(array[one],array[two]);
			++one;
			++two;
			start = two;
			end = one;
		}
	}
}
};
int main()
{
	int a[10] = {2,4,6,1,3,5,7};
	Solution s;
	vector<int> v(a,a+7);
	s.reOrderArray(v);
	return 0;
}