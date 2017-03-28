#pragma  once
#include <vector>

//λͼ��ר�������ж������Ƿ���ڣ�����ͳ�����ݳ��ֵĴ���
class BitMap
{
public:
	BitMap(size_t N = 1024)//N������Ҫ�жϵ����ݸ���
	{
		_array.resize((N>>5) + 1);//�൱��(N/32)+1,���Ϊ��Ҫ���ٵ��ֽڸ���
	}

	void Set(size_t value)//��״̬������Ϊ�У���0��Ϊ1
	{
		size_t index = value >> 5;//�����������±꣬���ڼ�������
		size_t num = value % 32;//����ڼ�λ
		
		_array[index] |= 1<<num;//���ض�λ��1
	}

	void ReSet(size_t value)//��״̬������Ϊ�ޣ���1��Ϊ0
	{
		size_t index = value >> 5;//�����������±꣬���ڼ�������
		size_t num = value % 32;//����ڼ�λ

		_array[index] &= (~(1<<num));//���ض�λ��0
	}

	bool Test(size_t value)
	{
		size_t index = value >> 5;//�����������±꣬���ڼ�������
		size_t num = value % 32;//����ڼ�λ

		return _array[index] & (1<<num);
	}
protected:
	std::vector<size_t> _array;//ÿ��size_t���ж�32�����Ƿ����
};

void TestBitMap()
{
	BitMap bm((size_t)-1);

	bm.Set(2);
	bm.Set(20);
	bm.Set(200);
	bm.Set(2000);
	bm.Set(20000);
	bm.Set(200000);
	bm.Set(2000000);
	bm.Set(20000000);

	bm.ReSet(2);
	bm.ReSet(2000);
	bm.ReSet(2000000);
	bm.ReSet(20000000);
	
	cout<<bm.Test(2)<<endl;
	cout<<bm.Test(20)<<endl;
	cout<<bm.Test(200)<<endl;
	cout<<bm.Test(2000)<<endl;
	cout<<bm.Test(20000)<<endl;
	cout<<bm.Test(200000)<<endl;
	cout<<bm.Test(2000000)<<endl;
	cout<<bm.Test(20000000)<<endl;
}