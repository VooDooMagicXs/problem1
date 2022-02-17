#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;
int * TheSmallestNumbers (vector < int >arr, int n)
{
  int firstmin = MAX, secmin = MAX, thirdmin = MAX;
  for (int i = 0; i < n; i++)
    {
      if (arr[i] < firstmin)
	{
	  thirdmin = secmin;
	  secmin = firstmin;
	  firstmin = arr[i];
	}
      else if (arr[i] < secmin)
	{
	  thirdmin = secmin;
	  secmin = arr[i];
	}
      else if (arr[i] < thirdmin)
	{
	  thirdmin = arr[i];
	}
    }

  int *array_ = new int[3];
  array_[0] = firstmin;
  array_[1] = secmin;
  array_[2] = thirdmin;
  return array_;
}

int main ()
{
  setlocale (LC_ALL, "Rus");
  ifstream fin ("input.txt");
  int n;
  vector < int >arr;

  if (!fin.good ())
    {
      cout << "file input.txt not found\n";
    }
  else
    {
      while (fin >> n)
	{
	  arr.push_back (n);
	}
      cout << "the following numbers are in the file:\n";
      for (int i = 0; i < arr.size (); i++)
	{
	  cout << arr[i] << " ";

	}
      cout << endl;
      int size = arr.size ();
      int *pointer = TheSmallestNumbers (arr, size);
      cout << "the smallest numbers: \n";
      for (int i = 0; i < 3; i++)
	{
	  cout << pointer[i] << " ";
	}
      cout << endl;
      int indexes[3];
      for (int i = 0; i < arr.size (); i++)
	{
	  if (arr[i] == pointer[0])
	    {
	      indexes[0] = i;
	    }
	  else if (arr[i] == pointer[1])
	    {
	      indexes[1] = i;
	    }
	  else if (arr[i] == pointer[2])
	    {
	      indexes[2] = i;
	    }
	}
      cout << "their indexes: \n";
      for (int i = 0; i < 3; i++)
	{
	  cout << indexes[i] << " ";
	}
      string path = " output.txt.txt";
      ofstream fout;
      fout.open (path);
      if (!fout.is_open ())
	{
	  cout << "net";
	}
      else
	{
	  for (int i = 0; i < 3; i++)
	    {
	      fout << indexes[i] << " ";
	    }
	}
      fout.close ();
    }
  fin.close ();
  return 0;
}