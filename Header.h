#pragma once
template<class T> class TVector
{
protected:
	T* pVector;
	int size;
	int startIndex;
public:
	bool operator==(const TVector& v)
	{
		bool flag = 0;
		if ((size == v.size) && (startIndex == v.startIndex))
		{
			int n = 0;
			for (int i = 0; i < size; i++)
			{
				if ((pVector[i] == v.pVector[i])) n++;
			}
			if (n == size) flag == 1;
		}
		return flag;
	}

	template<class T> T& operator[] (int pos)
	{
		return pVector[pos - startIndex];
	}

	template<class T> TVector<T> operator=(const TVector& v)
	{
		if (this != &v)
		{
			if (size != v.size)
			{
				delete pVector;
				pVector = new T[v.size];
			}
		}
		size = v.size;
		startIndex = v.startIndex;
		for (int i = 0; i < size;i++) { pVector[i] = v.pVector[i]; }
		return this;
	}

	template<class T> TVector<T> operator+(const TVector<T>& v)
	{
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
		{
			temp.pVector[i] = pVector[i] + pVector[i];
		}
		return temp;
	}
	template<class T> TVector<T> operator-(const TVector<T>& v)
	{
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
		{
			temp.pVector[i] = pVector[i] - pVector[i];
		}
		return temp;
	}

	template<class T> TVector<T> operator*(const TVector<T>& v)
	{
		TVector temp(size, startIndex);
		for (int i = 0; i < size; i++)
		{
			temp.pVector[i] = pVector[i] * pVector[i];
		}
		return temp;
	}

	

	template<class T>TVector(int s = 10, int si = 0)
	{
		size = s;
		startIndex = si;
		pVector = new T[size];
		for (int i = 0; i < size; i++) { pVector[i] = 0; }
	}
	template<class T> TVector(const TVector& v)
	{
		size = v.size;
		startIndex = v.startIndex;
		pVector = new T[size];
		for (int i = 0; i < size; i++) { pVector[i] = v.pVector[i]; }
	}
	~TVector()
	{
		delete[]pVector;
		pVector = nullptr;
	}

	friend istream& operator>>(istream& in, tVector& v)
	{
		for (int i = 0; i < v.size; i++) { in >> pVector[i]; }
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.size; i++) { out << pVector[i] << ' '; }
		return out;
	}
};

template<class T> class TMatrix
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& int);
	TMatrix(const TVector<TVector<T>>& int);
	bool operator==(const Tmatrix& int mt)
	{
		return TVector <TVector<T>>::operator==(mt);
	}
	bool operator=(const TMatrix& int);

	friend isrteam& operator >>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.size, i++) { in >> mt.pVector[i]; }
		return in;
	}
	template <class T> TMatrix(int s) :TVector <TVector<T>>(s)
	{
		for (int i = 0; i < s; i++) 
		{
			this->pVector[i] = TVector<T>(s - i, i);
		}
	}
	template<class T> TMatrix<T>& operator=(const TMatrix <T>& mt)
	{
		if (this != &mt)
		{
			if (this->size != mt.size) 
			{
				delete[]this->pVector;
				this->pVector = new TVector<T>[mt.size];
			}
			this->size = mt.size;
			this.startIndex = mt.startIndex;
			for (int i = 0; i < this->size; i++)
			{
				this->pVector[i] = mt.pVector[i];
			}
		}
		return *this;
	}
	template <class T> TMatrix operator*(const TMatrix& mt)
	{
		TMatrix <T> temp(this->getsize());
		int i, j = 0, k;
		for (i = 0; i < temp.size; ++i) {
			for (k = i; k < j + 1; ++k) {
				temp[i][k] += this->pVector[i][k] * mt.pVector[k][i];
			}
		}
		return temp;
	}
	template<class T> TMatrix<T> operator+(const TMatrix<T>& mt)
	{
		return TVector<TVector >> ::operator+(mt);
	}
	/*
	в мэйне обратитьс€ к этим функци€м и выбрать
	протестить
	как сделать экземпл€р матрицы
	*/

};

