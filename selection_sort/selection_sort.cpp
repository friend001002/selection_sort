#include <iostream>
#include <vector>

using namespace std;

class Selection_sort_ex : public runtime_error
{
  public:

  explicit Selection_sort_ex(const char *msg) : runtime_error(msg)
  {
  }

  explicit Selection_sort_ex(string& msg) : runtime_error(msg)
  {
  }

  virtual ~Selection_sort_ex()
  {
  }

  virtual const char* what() const noexcept
  {
    return runtime_error::what();
  }
};

template<class T>
class Selection_sort
{
  public:

  Selection_sort(vector<T>& in) : data_(in)
  {

  }

  virtual ~Selection_sort()
  {
    cout << "~Selection_sort\n";

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

  vector<T> Sort() noexcept(false)
  {
    if (0 == data_.size())
    {
      cerr << "No data to sort!\n";
      //return false;
      throw Selection_sort_ex("No data to sort");
    }

    size_t size { data_.size() };

    for (size_t i {}; i < size; ++i)
    {
      T min = data_.at(i);
      size_t min_ind{};
      bool swap{ false };

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

    //out = data_;

    return data_;
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
  cout << "Error codes:\n";

  do
  {
    vector<int> in { 5, 4, 3, 2, 4, 1, 0, 3 };

    Selection_sort<int> ss(in);

    vector<int> ret;

    cout << "Orig:   ";

    for (int i : in)
    {
      cout << i << ' ';
    }

    cout << endl;

    bool succ { ss.Sort(ret) };

    cout << "Sorted: ";

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
  }
  while (false);

  cout << "Exceptions:\n";

  do
  {
    vector<int> in { 5, 4, 3, 2, 4, 1, 0, 3 };

    Selection_sort<int> ss(in);

    cout << "Orig:   ";

    for (int i : in)
    {
      cout << i << ' ';
    }

    cout << endl;

    cout << "Sorted: ";

    try
    {
      vector<int> ret = ss.Sort();

      for (int i : ret)
      {
        cout << i << ' ';
      }
    }
    catch (Selection_sort_ex& ex)
    {
      cerr << "Exception: " << ex.what() << endl;
    }

    cout << endl;
  }
  while (false);

  cin.get();

  return 0;
}
