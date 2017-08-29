#pragma once
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef long long INT64;                 //��long long����������
const INT64 INVALID = 0xcccccccccccccccc; //���ֵ
const INT64 MAX =  9223372036854775807;   //���ֵ(0x7FFFFFFFFFFFFFFF)
const INT64 MIN = -9223372036854775808;   //��Сֵ(0x8000000000000000)

class BigData
{
public:
	friend ostream& operator<<(ostream& _cout,const BigData& bd);
	
	BigData()//�޲ι��캯��
		:_pData("")
		,_value(INVALID)
	{}
	BigData(INT64 value)//��һ���������Ĺ��캯��(ע��Ҫ��֤MIN<value<MAX����������)
	{
		if(value==0)
		{
			_pData.resize(3);
			_pData[0] = '+';//Ĭ��0������
			_pData[1] = '0';
			_pData[2] = '\0';
			return;
		}

		_value = value;

		char count = 0;//ͳ������������λ��
		INT64 tmp = value;//������ʱ����tmp������
		//ͳ�����������ж���λ
		while(tmp)
		{
			++count;
			tmp /= 10;
		}
		_pData.resize(count+2);//�����ź�'\0'�࿪�������ֽ�
		//ȷ�Ϸ���
		if (value > 0)
			_pData[0] = '+';
		else
			_pData[0] = '-';

		//�Ӻ���ǰ���ַ����鸳ֵ
		tmp = value;
		if (tmp < 0)
			tmp = 0 - tmp;//���tmp�Ǹ����������Ϊ����
		for (int i = count; i > 0; --i)
		{
			char c = tmp%10 + '0';//ȡ���λ
			_pData[i] = c;
			tmp /= 10;
		}
	}
	BigData(const char* s)//���ַ�����������Ĺ��캯��
		:_value(0)
	{
  		int len = strlen(s);//�������ַ����ĳ���
		_pData.resize(len+2,0);//Ϊ����λ��'\0'�࿪�������ռ�
		char sign = '+';//Ĭ�Ϸ���Ϊ��
		char* str = (char*)s;//��һ���ַ���ָ��s
		size_t size = 0;//��¼ʵ����Ч���ַ�������

		//����ǰ���'0'��' '(����"00003526727"  "   6767867")
		while(*str == '0' || *str == ' ')
			++str;

		//Ԥ��"000000" �� "     "
		if (*str == '\0')
		{
			_value = 0;
			_pData[0] = sign;//Ĭ��0Ϊ��
			_pData[1] = '0';
			_pData.resize(3);//'+' '0' '\0'
			return;
		}

		//ȷ�Ϸ���
		if (str[0] == '-' || str[0] == '+')
		{
			sign = *str++;
		}

		//Ԥ��"+000006458"  "-    648"
		while(*str == '0' || *str == ' ')
			++str;

		//Ԥ��"+000000" �� "-     "
		if (*str == '\0')
		{
			_value = 0;
			_pData[0] = sign;
			_pData[1] = '0';
			_pData.resize(3);
			return;
		}

		//�ӵ�1λ��ʼ��ֵ����0λ�ŷ���λ
		for (int i = 1; i <= len; ++i)
		{
			//ֻ�����������ַ������ַ������_value�и�ֵ
			if(*str >= '0' && *str <= '9')
			{
				_value = _value*10 + (*str - '0');
				_pData[i] = *str;
				++size;
				str++;
			}
			else
			{
				if(i == 1)//����"abc2654738"
					_pData[i] = '0';
				break;
			}
		}

		_pData[0] = sign;//��0��λ�ø�ֵΪ����λ
		_pData.resize(size+2);//���ô�С	

		//ȷ��_value�ķ���
		if (sign == '-')
			_value = 0 - _value;
	}

	BigData operator+(BigData& bd)
	{
		BigData* l = this;//�������
		BigData* r = &bd;//�Ҳ�����

		int lSize = l->_pData.size();
		int rSize = r->_pData.size();
		//���ϳ����������������
		if (lSize < rSize)
		{
			swap(l,r);
			swap(lSize,rSize);
		}
		//����������ݳ���һ�����ͽ��������ţ�����������������
		if (lSize == rSize)
		{
			if (strcmp(l->_pData.c_str()+1,r->_pData.c_str()+1) < 0)
			{
				swap(l,r);
				swap(lSize,rSize);
			}
		}

		//��������ͬ�ţ���������ݷ�����ͬ��
		if (l->_pData[0] == r->_pData[0])
		{
			//��������������һ�������
			if (l->IsOverFlow() || r->IsOverFlow())
				return BigData(l->ADD(r->_pData).c_str());//���������������ַ�����Ӻ���

			//�������ݶ�û�����������п������
			else
			{
				//ͬ�����������������  5 - 2 < 4
				if (l->_pData[0] == '+' && MAX - l->_value < r->_value)
				{
					return BigData(l->ADD(r->_pData).c_str());//���������������ַ�����Ӻ���
				}
				//ͬ�Ÿ��������������  -5 - (-3) > -3
				else if (l->_pData[0] == '-' && MIN - l->_value > r->_value)
				{
					return BigData(l->ADD(r->_pData).c_str());//���������������ַ�����Ӻ���
				}
				//�������ݶ�û���������Ҳû�����
				else
				{
					//ֱ������������ݣ�Ȼ������ʱ���󷵻�
					return BigData(l->_value+r->_value);
				}
			}
		} 
		//����������ţ�����ķ���Ϊ���ݽϴ�����ݵķ��ţ������������
		else
		{
			//�������ݶ�û���������϶�û���
			if (!l->IsOverFlow() && !r->IsOverFlow())
			{
				//ֱ������������ݣ�Ȼ������ʱ���󷵻�
				return BigData(l->_value+r->_value);
			}
			//��������������һ�������
			else
			{
				return BigData(l->SUB(r->_pData).c_str());//���������������ַ����������
			}
		}
	}
	BigData operator-(BigData& bd)
	{
		BigData* l = this;//�������
		BigData* r = &bd;//�Ҳ�����

		int lSize = l->_pData.size();
		int rSize = r->_pData.size();
		//���ϳ����������������
		if (lSize < rSize)
		{
			swap(l,r);
			swap(lSize,rSize);
		}
		//����������ݳ���һ�����ͽ��������ţ�����������������
		if (lSize == rSize)
		{
			if (strcmp(l->_pData.c_str()+1,r->_pData.c_str()+1) < 0)
			{
				swap(l,r);
				swap(lSize,rSize);
			}
		}

		//��������ͬ��
		if (l->_pData[0] == r->_pData[0])
		{
			//�������ݶ�û���������϶�Ҳû���
			if (!l->IsOverFlow() && !r->IsOverFlow())
			{
				//ֱ������������ݣ�Ȼ������ʱ���󷵻�
				return BigData(l->_value - r->_value);
			}
			//��������������һ�������,�����ַ����������
			else
			{
				return BigData(l->SUB(r->_pData).c_str());
			}
		}
		//�����������
		else
		{
			//��������������һ������ˣ�ֱ�ӵ����ַ�����Ӻ���
			if (l->IsOverFlow() || r->IsOverFlow())
			{
				return BigData(l->ADD(r->_pData).c_str());
			}
			//�������ݶ�û�����������п������Ҳ�п��ܲ����
			else
			{
				//������������������  5 - 2 < 4
				if (l->_pData[0] == '+' && MAX - l->_value < r->_value)
				{
					return BigData(l->ADD(r->_pData).c_str());//���������������ַ�����Ӻ���
				}
				//��Ÿ��������������  -5 - (-3) > -3
				else if (l->_pData[0] == '-' && MIN - l->_value > r->_value)
				{
					return BigData(l->ADD(r->_pData).c_str());//���������������ַ�����Ӻ���
				}
				//�������ݶ�û���������Ҳû�����
				else
				{
					//ֱ������������ݣ�Ȼ������ʱ���󷵻�
					return BigData(l->_value-r->_value);
				}
			}
		}
	}
	BigData operator*(BigData& bd)
	{
		BigData* l = this;//�������
		BigData* r = &bd;//�Ҳ�����

		int lSize = l->_pData.size();
		int rSize = r->_pData.size();

		//���ϳ����������������
		if (lSize < rSize)
		{
			swap(l,r);
			swap(lSize,rSize);
		}

		//��������ͬ��,����������Ϊ��
		if (l->_pData[0] == r->_pData[0])
		{
			//������һ����������������ַ����˷�����
			if (l->IsOverFlow() || r->IsOverFlow())
			{
				return BigData(l->MUL(r->_pData).c_str());
			}
			//�������ݶ�û���������������Ҳ���ܲ����
			else
			{
				//���������������  5 / 2 < 4
				if (MAX / l->_value < r->_value)
				{
					return BigData(l->MUL(r->_pData).c_str());//���������������ַ�����˺���
				}
				//�������ݶ�û���������Ҳû�����
				else
				{
					//ֱ������������ݣ�Ȼ������ʱ���󷵻�
					return BigData(l->_value*r->_value);
				}
			}
		}

		 //����������ţ�������Ϊ��
		else                       
		{
			//������һ����������������ַ����˷�����
			if (l->IsOverFlow() || r->IsOverFlow())
			{
				return BigData(l->MUL(r->_pData).c_str());
			}
			//�������ݶ�û���������������Ҳ���ܲ����
			else
			{
				//���������������  -5 / (-3) > 3
				if (MIN / l->_value > r->_value)
				{
					return BigData(l->MUL(r->_pData).c_str());//���������������ַ�����˺���
				}
				//�������ݶ�û���������Ҳû�����
				else
				{
					//ֱ������������ݣ�Ȼ������ʱ���󷵻�
					return BigData(l->_value*r->_value);
				}
			} 
		}
	}
	BigData operator/(BigData& bd)
	{
		if(strcmp(bd._pData.c_str()+1,"0")==0)//��ֹ����Ϊ0
			assert(false);
		int lSize = _pData.size();
		int rSize = bd._pData.size();

		//�������С���Ҳ��������߱�����Ϊ0�����Ϊ0
		if (lSize < rSize  || strcmp(_pData.c_str()+1,"0")==0)
			return BigData((INT64)0);
		//�������ݾ���ֵ��ȣ����Ϊ1��-1
		else if (lSize == rSize && strcmp(_pData.c_str()+1,bd._pData.c_str()+1)==0)
		{
			if(_pData[0] != bd._pData[0])
				return BigData((INT64)-1);
			else
				return BigData((INT64)1);
		}
		//�Ҳ�����Ϊ+1��-1�����Ϊ +������� �� -�������
		else if (rSize == 3 && bd._pData[1] == '1')
		{
			if(bd._pData[0] == '+')
			{
				return BigData(_pData.c_str());
			}
			else
			{
				string tmp = _pData;
				tmp[0] = '-';
				return BigData(tmp.c_str());
			}
		}
		else
		{
			//������һ���������
			if (IsOverFlow() || bd.IsOverFlow())
			{
				return BigData(DIV(bd._pData).c_str());
			}
			//�������ݶ�û��������Ҳû���
			else
			{
				return BigData(_value/bd._value);
			}
		}
	}

protected:
	bool IsOverFlow()//�ж������Ƿ����
	{
		//����ǰ�ַ����ĳ���
		int len = _pData.size();
		
		//��INT64�����ֵ����Сֵ�ĳ������Ƚϣ��������MAX��MIN�ĳ��ȣ�˵�����
		if (len > 21)//"+9223372036854775807\0"  "-9223372036854775808\0"(21λ)
		{
			return true;
		}
		else if (len < 21)//�������MAX��MIN�ĳ��ȣ�˵�����
		{
			return false;
		}
		else//�������MAX��MIN�ĳ��ȣ�����Ҫ�����ж�
		{
			if (_pData[0] == '+' && strcmp(_pData.c_str(),"+9223372036854775807")>0)
				return true;
			if (_pData[0] == '-' && strcmp(_pData.c_str(),"-9223372036854775808")>0)
			    return true;
			return false;
		}
	}
	string ADD(string& s)//�ַ����ӷ�
	{
		int lSize = _pData.size();
		int rSize = s.size();
		
		string ret;//���巵��ֵ
		ret.resize(lSize+1);//99999+99=100098(λ�����Ϊ�������+1)
		
		char step = 0;//��λ
		char cRet = 0;
		for (int i = 2; i < lSize; ++i)
		{
			//�Ҳ�������λ����û���꣬��+��+��λ
			if (rSize-i > 0)
			{
				cRet = _pData[lSize-i] - '0' + s[rSize-i] -'0'+ step;
			}
			//�Ҳ������������+��λ
			else
			{
				cRet = _pData[lSize-i] - '0' + step;
			}
			step = cRet/10;
			cRet = cRet%10;
			ret[lSize+1-i] = cRet + '0';
		}
		ret[0] = _pData[0];   //ȷ������λ
		ret[1] = step+'0';    //�������һ����λ

		return ret;
	}
	string SUB(string& s)//�ַ�������
	{
		int lSize = _pData.size();
		int rSize = s.size();

		string ret;//���巵��ֵ
		ret.resize(lSize+1);//99999-(-99)=100098(λ�����Ϊ�������+1��)

		char step = 0;//��λ
		char cRet = 0;
		for (int i = 2; i < lSize; ++i)
		{
			//�Ҳ�������λ����û���꣬��-��-��λ
			if (rSize-i > 0)
			{
				cRet = (_pData[lSize-i]-'0') - (s[rSize-i]-'0') - step; 
				step = 0;
			}
			//�Ҳ������������-��λ
			else
			{
				cRet = _pData[lSize-i] - '0' - step;
				step = 0;
			}

			if(cRet < 0)//�������ͽ��н�λ
			{
				cRet += 10;//��ǰ0λ+10
				step = 1;//��ǰ���һλ
			}

			ret[lSize+1-i] = cRet + '0';
		}
		ret[0] = _pData[0];   //ȷ������λ
		ret[1] = step+'0';    //�������һ����λ
		
		return ret;
	}
	string MUL(string& s)
	{
		int lSize = _pData.size();
		int rSize = s.size();

		string ret;//���巵��ֵ
		//������ΪlSize+rSize-2λ "+9999\0" * "+99\0" = "+989901\0"
		ret.resize(lSize+rSize-2);

		char step = 0;//��λ
		char count = 0;//��λ
		char cRet = 0;
		for (int i = 2; i < rSize; ++i)//�Ҳ������Ƚ϶̣�Ӧ�������ѭ��
		{
			step = 0;
			for (int j = 2; j < lSize; ++j)//��������Ƚϳ���Ӧ�����ڲ�ѭ��
			{
				cRet = (s[rSize-i]-'0') * (_pData[lSize-j]-'0') + step;
				if(count > 0)
					cRet += ret[lSize+rSize-2-j-count] - '0';
				step = cRet/10;
				cRet %= 10;
				ret[lSize+rSize-2-j-count] = cRet + '0';
			}
			count++;//ÿ����ǰ��һλ
			ret[rSize-1-count] += step + '0';//�������һ����λ
		}

		//ȷ������ķ��ţ�ͬ��Ϊ�������Ϊ��
		if (_pData[0] == s[0])
			ret[0] = '+';
		else
            ret[0] = '-';

		return ret;
	}
	string DIV(string& s)
	{
		int lSize = _pData.size();
		int rSize = s.size();

		string ret;//���巵��ֵ
		//������ΪlSizeλ "+9999\0" * "+1\0" = "+9999\0"
		ret.reserve(lSize); 

		string sleft(_pData.c_str(),rSize-1);//������
		string sright(s.c_str(),rSize-1);//����
		int index = rSize-1;
		while(index < lSize)
		{
			//������
			while (sleft.size()==sright.size() && strcmp(sleft.c_str(),sright.c_str())<0)
			{
				sleft += _pData[index++];//��λ
				ret.push_back('0');
				if (index > lSize)
					break;
			}
			//����
			int count = 0;
			while(sleft.size()>sright.size() ||\
				 (sleft.size()==sright.size()&&strcmp(sleft.c_str(),sright.c_str())>0))
			{
				BigData tmp(sleft.c_str());
				sleft = tmp.SUB(BigData(sright.c_str())._pData);
				++count;
				sleft = BigData(sleft.c_str())._pData;//ȥ�������0
				sleft = string(sleft.c_str(),sleft.size()-1);//ȥ�������'\0'
			}
			ret.push_back(count+'0');
			sleft += _pData[index++];//��λ
		}
		//ȷ������ķ��ţ�ͬ��Ϊ�������Ϊ��
		if (_pData[0] == s[0])
			ret[0] = '+';
		else
			ret[0] = '-';
		return ret;
	}

private:
	string _pData;
	INT64 _value;
};

ostream& operator<<(ostream& _cout,const BigData& bd)
{
	_cout<<bd._pData.c_str();
	return _cout;
}