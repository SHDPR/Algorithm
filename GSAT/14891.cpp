#include <iostream>
using namespace std;

int aoo[8];
int boo[8];
int coo[8];
int doo[8];

void rotate(int input[], int dir)
{
  if(dir == 1)
  {
    int tmp = input[7];
    for(int idx = 6; idx >= 0; idx--)
    {
      input[idx + 1] = input[idx];
    }
    input[0] = tmp;
  }
  else if(dir == -1)
  {
    int tmp = input[0];
    for(int idx = 0; idx < 7; idx++)
    {
      input[idx] = input[idx + 1];
    }
    input[7] = tmp;
  }
}


int main()
{
  char input[8];

  cin >> input;
  for(int idx = 0; idx < 8; idx++)
  {
    aoo[idx] = (int)(input[idx] - '0');
  }

  cin >> input;
  for(int idx = 0; idx < 8; idx++)
  {
    boo[idx] = (int)(input[idx] - '0');
  }

  cin >> input;
  for(int idx = 0; idx < 8; idx++)
  {
    coo[idx] = (int)(input[idx] - '0');
  }

  cin >> input;
  for(int idx = 0; idx < 8; idx++)
  {
    doo[idx] = (int)(input[idx] - '0');
  }




  int op;
  cin >> op;

  for(int idx = 0; idx < op; idx++)
  {

    bool first = (aoo[2] - boo[6]);
    bool secnd = (boo[2] - coo[6]);
    bool third = (coo[2] - doo[6]);


    int num, dir;
    cin >> num >> dir;

    switch(num)
    {
      case 1 :
        rotate(aoo, dir);
        if(first)
        {
          dir *= -1;
          rotate(boo, dir);
          if(secnd)
          {
            dir *= -1;
            rotate(coo, dir);
            if(third)
            {
              dir *= -1;
              rotate(doo, dir);
            }
          }
        }
        break;

      case 2 :
        rotate(boo, dir);
        if(first)
        {
          rotate(aoo, dir * (-1));
        }
        if(secnd)
        {
          dir *= -1;
          rotate(coo, dir);
          if(third)
          {
            dir *= -1;
            rotate(doo, dir);
          }
        }
        break;

      case 3 :
        rotate(coo, dir);
        if(third)
        {
          rotate(doo, dir * (-1));
        }
        if(secnd)
        {
          dir *= -1;
          rotate(boo, dir);
          if(first)
          {
            dir *= -1;
            rotate(aoo, dir);
          }
        }
        break;

      case 4 :
        rotate(doo, dir);
        if(third)
        {
          dir *= -1;
          rotate(coo, dir);
          if(secnd)
          {
            dir *= -1;
            rotate(boo, dir);
            if(first)
            {
              dir *= -1;
              rotate(aoo, dir);
            }
          }
        }
        break;
    }
  }


  int score = 0;
  if(aoo[0] == 1)
    score += 1;

  if(boo[0] == 1)
    score += 2;

  if(coo[0] == 1)
    score += 4;

  if(doo[0] == 1)
    score += 8;

  cout << score;

}
