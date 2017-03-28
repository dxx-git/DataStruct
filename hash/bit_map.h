#pragma  once
#include <vector>

//位图：专门用来判断数据是否存在，不能统计数据出现的次数
class BitMap
{
public:
	BitMap(size_t N = 1024)//N代表需要判断的数据个数
	{
		_array.resize((N>>5) + 1);//相当于(N/32)+1,结果为需要开辟的字节个数
	}

	void Set(size_t value)//将状态由无置为有，即0变为1
	{
		size_t index = value >> 5;//代表整数的下标，即第几个整数
		size_t num = value % 32;//代表第几位
		
		_array[index] |= 1<<num;//将特定位置1
	}

	void ReSet(size_t value)//将状态由有置为无，即1变为0
	{
		size_t index = value >> 5;//代表整数的下标，即第几个整数
		size_t num = value % 32;//代表第几位

		_array[index] &= (~(1<<num));//将特定位置0
	}

	bool Test(size_t value)
	{
		size_t index = value >> 5;//代表整数的下标，即第几个整数
		size_t num = value % 32;//代表第几位

		return _array[index] & (1<<num);
	}
protected:
	std::vector<size_t> _array;//每个size_t可判断32个数是否存在
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