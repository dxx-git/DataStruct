#pragma once
// �Ǹ���Դ���·��--Dijkstra(�Ͽ�˹��)
// ��src��������������·��
void _Dijkstra(int src, W* dist, int* path, bool* vSet, int size, const W& maxValue)
{
	//
	// 1.dist��ʼ��src����������ĵľ���
	// 2.path��ʼ��src�����������·��
	// 3.��ʼ�����㼯��
	//
	for (int i = 0; i < size; ++i)
	{
		dist[i] = _GetWeight(src, i, maxValue);
		path[i] = src;
		vSet[i] = false;
	}

	// ��src���뼯��
	vSet[src] = true;

	int count = size;
	while(count--)
	{
		//
		// ѡ����src�������ӵı�����С�ı�
		// src->min
		W min = maxValue;
		int minIndex = src;
		for (int j = 0; j < size; ++j)
		{
			if (vSet[j] == false && dist[j] < min)
			{
				minIndex = j;
				min = dist[j];
			}
		}

		vSet[minIndex] = true;
		for (int k = 0; k < size; ++k)
		{
			if(k == src)
				continue;

			//  
			// ����src->k�ľ���
			// ���dist(src,min)+dist(min, k)��ȨֵС��dist(src, k)
			// �����dist(src,k)��path(src->min->k)
			//
			W w = _GetWeight(minIndex, k, maxValue);
			if (vSet[k] == false && dist[minIndex] + w < dist[k])
			{
				dist[k] = dist[minIndex] + w;
				path[k] = minIndex;
			}
		}
	}
}

void _Dijkstra_OP(int src, W* dist, int* path,
	bool* vSet, int size, const W& maxValue)
{
	//
	// 1.dist��ʼ��src����������ĵľ���
	// 2.path��ʼ��src�����������·��
	// 3.��ʼ�����㼯��
	//
	for (int i = 0; i < size; ++i)
	{
		dist[i] = _GetWeight(src, i, maxValue);
		path[i] = src;
		vSet[i] = false;
	}

	struct Compare
	{
		bool operator()(const pair<W, int>& lhs, const pair<W, int>& rhs)
		{
			return lhs.first < rhs.first;
		}
	};

	Heap<pair<W, int>, Compare> minHeap;
	for (int i = 0; i < size; ++i)
	{
		if (dist[i] < maxValue)
		{
			minHeap.Push(make_pair(dist[i], i));
		}
	}

	// ��src���뼯��
	vSet[src] = true;

	int count = size;
	while(count--)
	{
		//
		// ѡ����src�������ӵı�����С�ı�
		// src->min

		if (minHeap.Empty())
			continue;

		int minIndex = minHeap.Top().second;
		minHeap.Pop();

		vSet[minIndex] = true;
		for (int k = 0; k < size; ++k)
		{
			// 
			// ���dist(src->min)+dist(min, k)��ȨֵС��dist(src, k)
			// �����dist(src,k)��path(src->min->k)
			//
			W w = _GetWeight(minIndex, k, maxValue);
			if (vSet[k] == false && dist[minIndex] + w < dist[k])
			{
				dist[k] = dist[minIndex] + w;
				path[k] = minIndex;

				minHeap.Push(make_pair(dist[k], k));
			}
		}
	}
}

void PrintPath(int src, W* dist, int* path, int size)
{
	int* vPath = new int[size];
	for (int i = 0; i < size; ++i)
	{
		if (i != src)
		{
			int index = i, count = 0;
			do{
				vPath[count++] = index;
				index = path[index];
			}while (index != src);

			vPath[count++] = src;

			//cout<<"���㣺"<<_linkTable[src]._vertex\
			<<"->���㣺"<<_linkTable[i]._vertex<<"��·��Ϊ��";
			cout<<src<<","<<i<<"��·��Ϊ:";
			while(count)
			{
				//cout<<_linkTable[ vSet[--count] ]._vertex<<"->";
				cout<<vPath[--count]<<"->";
			}

			cout<<"·������Ϊ��"<<dist[i]<<endl;
		}
	}
}
