#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Selection_sort
{
  public:

  Selection_sort(vector<T>& in) : data_(in)
  {

  }

  virtual ~Selection_sort()
  {
    data_.clear();
    data_.shrink_to_fit();
  }

  bool Sort(vector<T>& out)
  {
    if (0 == data_.size())
    {
      cerr << "No data to sort!\n";
      return false;
    }

    size_t size { data_.size() };

    for (size_t i {}; i < size; ++i)
    {
      T min = data_.at(i);
      size_t min_ind {};
      bool swap { false };

      for (size_t j { i + 1 }; j < size; ++j)
      {
        if (data_.at(j) < min)
        {
          min = { data_.at(j) };
          min_ind = { j };
          swap = { true };
        }
      }

      if (swap)
      {
        Swap(i, min_ind);
      }
    }

    out = data_;

    return true;
  }

  private:

  void Swap(size_t a, size_t b)
  {
    T tmp { data_.at(a) };
    data_.at(a) = { data_.at(b) };
    data_.at(b) = { tmp };
  }

  vector<T>& data_;
};

int main()
{
  vector<int> in { 5, 4, 3, 2, 4, 1, 0, 3 };

  Selection_sort<int> ss(in);

  vector<int> ret;

  bool succ { ss.Sort(ret) };

  if (succ)
  {
    for (int i : ret)
    {
      cout << i << ' ';
    }

    cout << endl;
  }
  else
  {
    cerr << "Faied\n:";
  }

  cin.get();

  return 0;
}
