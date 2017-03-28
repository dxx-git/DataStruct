


template<class T>  
size_t BKDRHash(const T *str)  
{  
	register size_t hash = 0;  
	while (size_t ch = (size_t)*str++)  
	{         
		hash = hash * 131 + ch;   // Ҳ���Գ���31��131��1313��13131��131313..          
	}  
	return hash;  
}  
 
template<class T>  
size_t SDBMHash(const T *str)  
{  
	register size_t hash = 0;  
	while (size_t ch = (size_t)*str++)  
	{  
		hash = 65599 * hash + ch;         
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}  
	return hash;  
}  
  
template<class T>  
size_t RSHash(const T *str)  
{  
	register size_t hash = 0;  
	size_t magic = 63689;     
	while (size_t ch = (size_t)*str++)  
	{  
		hash = hash * magic + ch;  
		magic *= 378551;  
	}  
	return hash;  
}  

template<class T>  
size_t APHash(const T *str)  
{  
	register size_t hash = 0;  
	size_t ch;  
	for (long i = 0; ch = (size_t)*str++; i++)  
	{  
		if ((i & 1) == 0)  
		{  
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));  
		}  
		else  
		{  
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));  
		}  
	}  
	return hash;  
}  
  
template<class T>  
size_t JSHash(const T *str)  
{  
	if(!*str)        // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0  
		return 0;  
	register size_t hash = 1315423911;  
	while (size_t ch = (size_t)*str++)  
	{  
		hash ^= ((hash << 5) + ch + (hash >> 2));  
	}  
	return hash;  
}  
template<class T>  
size_t DEKHash(const T* str)  
{  
	if(!*str)        // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0  
		return 0;  
	register size_t hash = 1315423911;  
	while (size_t ch = (size_t)*str++)  
	{  
		hash = ((hash << 5) ^ (hash >> 27)) ^ ch;  
	}  
	return hash;  
}  
  
template<class T>  
size_t FNVHash(const T* str)  
{  
	if(!*str)   // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0  
		return 0;  
	register size_t hash = 2166136261;  
	while (size_t ch = (size_t)*str++)  
	{  
		hash *= 16777619;  
		hash ^= ch;  
	}  
	return hash;  
}  
  
template<class T>  
size_t DJBHash(const T *str)  
{  
	if(!*str)   // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0  
		return 0;  
	register size_t hash = 5381;  
	while (size_t ch = (size_t)*str++)  
	{  
		hash += (hash << 5) + ch;  
	}  
	return hash;  
}  

template<class T>  
size_t DJB2Hash(const T *str)  
{  
	if(!*str)   // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0  
		return 0;  
	register size_t hash = 5381;  
	while (size_t ch = (size_t)*str++)  
	{  
		hash = hash * 33 ^ ch;  
	}  
	return hash;  
}  
 
template<class T>  
size_t PJWHash(const T *str)  
{  
	static const size_t TotalBits       = sizeof(size_t) * 8;  
	static const size_t ThreeQuarters   = (TotalBits  * 3) / 4;  
	static const size_t OneEighth       = TotalBits / 8;  
	static const size_t HighBits        = ((size_t)-1) << (TotalBits - OneEighth);      

	register size_t hash = 0;  
	size_t magic = 0;     
	while (size_t ch = (size_t)*str++)  
	{  
		hash = (hash << OneEighth) + ch;  
		if ((magic = hash & HighBits) != 0)  
		{  
			hash = ((hash ^ (magic >> ThreeQuarters)) & (~HighBits));  
		}  
	}  
	return hash;  
}  
  
template<class T>  
size_t ELFHash(const T *str)  
{  
	static const size_t TotalBits       = sizeof(size_t) * 8;  
	static const size_t ThreeQuarters   = (TotalBits  * 3) / 4;  
	static const size_t OneEighth       = TotalBits / 8;  
	static const size_t HighBits        = ((size_t)-1) << (TotalBits - OneEighth);      
	register size_t hash = 0;  
	size_t magic = 0;  
	while (size_t ch = (size_t)*str++)  
	{  
		hash = (hash << OneEighth) + ch;  
		if ((magic = hash & HighBits) != 0)  
		{  
			hash ^= (magic >> ThreeQuarters);  
			hash &= ~magic;  
		}         
	}  
	return hash;  
}  


