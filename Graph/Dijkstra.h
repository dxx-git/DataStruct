#pragma once
// 非负单源最短路径--Dijkstra(迪科斯彻)
// 求src到其他顶点的最短路径
void _Dijkstra(int src, W* dist, int* path, bool* vSet, int size, const W& maxValue)
{
	//
	// 1.dist初始化src到其他顶点的的距离
	// 2.path初始化src到其他顶点的路径
	// 3.初始化顶点集合
	//
	for (int i = 0; i < size; ++i)
	{
		dist[i] = _GetWeight(src, i, maxValue);
		path[i] = src;
		vSet[i] = false;
	}

	// 将src加入集合
	vSet[src] = true;

	int count = size;
	while(count--)
	{
		//
		// 选出与src顶点连接的边中最小的边
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
			// 更新src->k的距离
			// 如果dist(src,min)+dist(min, k)的权值小于dist(src, k)
			// 则更新dist(src,k)和path(src->min->k)
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
	// 1.dist初始化src到其他顶点的的距离
	// 2.path初始化src到其他顶点的路径
	// 3.初始化顶点集合
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

	// 将src加入集合
	vSet[src] = true;

	int count = size;
	while(count--)
	{
		//
		// 选出与src顶点连接的边中最小的边
		// src->min

		if (minHeap.Empty())
			continue;

		int minIndex = minHeap.Top().second;
		minHeap.Pop();

		vSet[minIndex] = true;
		for (int k = 0; k < size; ++k)
		{
			// 
			// 如果dist(src->min)+dist(min, k)的权值小于dist(src, k)
			// 则更新dist(src,k)和path(src->min->k)
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

			//cout<<"顶点："<<_linkTable[src]._vertex\
			<<"->顶点："<<_linkTable[i]._vertex<<"的路径为：";
			cout<<src<<","<<i<<"的路径为:";
			while(count)
			{
				//cout<<_linkTable[ vSet[--count] ]._vertex<<"->";
				cout<<vPath[--count]<<"->";
			}

			cout<<"路径长度为："<<dist[i]<<endl;
		}
	}
}
