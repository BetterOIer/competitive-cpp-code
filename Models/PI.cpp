#include <iostream>
//#include <stdio.h>
#include <cstring>
using namespace std;
#define NUMLEN 10024 // must > 1
int compareBignum(const char *str1, const char *str2);
char *itoa(int num, char *str, int radix); //整数转字符串
class Bignum
{
    char iNum[NUMLEN];

public:
    Bignum()
    {
        memset(iNum, '\0', NUMLEN);
        // iNum[0] = '\0';
        // iNum[1] = '\0';
    }

    Bignum(char *num)
    {
        int i;
        for (i = 0; i < NUMLEN - 1; i++)
        {
            if (num[i] >= '0' && num[i] <= '9')
            {
                iNum[i] = num[i];
            }
            else if (num[i] == '\0')
            {
                iNum[i] = '\0';
                break;
            }
            else
            {
                iNum[0] = 'E';
                iNum[1] = '\0';
                break;
            }
        }
        //去掉前面的0
        if (iNum[0] == '0')
        {
            int num0 = 0;
            int len = strlen(iNum);
            for (i = 0; i < len; i++)
            {
                if (iNum[i] != '0')
                    break;
                else
                    num0++;
            }
            for (i = 0; i < len - num0; i++)
            {
                iNum[i] = iNum[i + num0];
            }
            iNum[i] = '\0';
            if (iNum[0] == '\0')
            {
                iNum[0] = '0';
                iNum[1] = '\0';
            }
        }
    }

public:
    Bignum operator+(const Bignum &str2) const
    {
        return jia(str2);
    }

public:
    Bignum operator*(const Bignum &str2) const
    {

        return chen(str2);
    }

public:
    Bignum operator/(const Bignum &str2) const
    {

        return chu(str2);
    }

public:
    Bignum operator-(const Bignum &str2) const
    {

        return jian(str2);
    }
    void display()
    {
        //  cout << "0="<<iNum[0] +'\12' << "  1="<< iNum[1] +'\12'<< endl;
        // cout << "this number is " << iNum << "   len=："<< len  << endl;
        printf("%s len=%d\n", iNum, strlen(iNum));
    }

public:
    bool operator==(const Bignum &str2) const
    {
        unsigned int i;
        bool ret;
        if (strlen(iNum) == strlen(str2.iNum))
        {
            for (i = 0; i < strlen(iNum); i++)
            {
                if (iNum[i] != str2.iNum[i])
                {
                    ret = false;
                    break;
                }
                ret = true;
            }
        }
        return ret;
    }

public:
    bool operator>(const Bignum &str2) const
    {
        unsigned int i;
        bool ret;
        if (strlen(iNum) > strlen(str2.iNum))
            ret = true;
        else if (strlen(iNum) < strlen(str2.iNum))
        {
            ret = false;
        }
        else
        {
            for (i = 0; i < strlen(iNum); i++)
            {
                if (iNum[i] > str2.iNum[i])
                {
                    ret = false;
                    break;
                }
                ret = true;
            }
        }
        return ret;
    }

public:
    bool operator<(const Bignum &str2) const
    {
        unsigned int i;
        bool ret;
        if (strlen(iNum) < strlen(str2.iNum))
            ret = true;
        else if (strlen(iNum) > strlen(str2.iNum))
        {
            ret = false;
        }
        else
        {
            for (i = 0; i < strlen(iNum); i++)
            {
                if (iNum[i] < str2.iNum[i])
                {
                    ret = false;
                    break;
                }
                ret = true;
            }
        }
        return ret;
    }
    Bignum jian(const Bignum &str2) const
    {
        Bignum temp;
        if (iNum[0] == 'E' || str2.iNum[0] == 'E' || iNum[NUMLEN - 2] == 'E' || str2.iNum[NUMLEN - 2] == 'E')
        {
            temp.iNum[0] = 'E';
            temp.iNum[1] = '\0';
            temp.iNum[NUMLEN - 2] = 'E';
            temp.iNum[NUMLEN - 1] = '\0';
            return temp;
        }
        int duo;
        char k, jie;
        int pos;
        int len, len2, i;

        int comp = compareBignum(iNum, str2.iNum);
        if (comp == 1)
        {
            //  cout << "zhengshu" <<endl;
            jie = '\0';
            len = strlen(iNum);
            len2 = strlen(str2.iNum);
            duo = len - len2;
            pos = len - 1;
            for (i = len2 - 1; i >= 0; i--) // 123456 123 6 3
            {
                if (str2.iNum[i] > (iNum[i + duo] - jie))
                {
                    k = '\12' + iNum[i + duo] - str2.iNum[i] - jie; // '\12'+str1.iNum[i+duo] -'0' - (str2.iNum[i]-'0')
                    jie = '\1';
                }
                else
                {
                    k = iNum[i + duo] - str2.iNum[i] - jie;
                    jie = '\0';
                }
                temp.iNum[pos] = k + '0';

                //   cout << pos << ":"<<str2.iNum[i]<<":"<< iNum[i+duo]<< ":"<<temp.iNum[pos]<<endl;
                pos = pos - 1;
            } // 123456 123 6 3
            for (i = len - len2 - 1; i >= 0; i--)
            {
                if (iNum[i] == '0' && jie == '\1')
                {
                    k = '\11';
                    jie = '\1';
                }
                else
                {
                    k = iNum[i] - '0' - jie;
                    jie = '\0';
                }
                temp.iNum[pos] = k + '0';
                //      cout << pos << "*"<< iNum[i]<< ":"<<temp.iNum[pos]<<endl;

                pos = pos - 1;
            }
            int num0 = 0; //去前面的0
            for (i = 0; i < len; i++)
            {
                if (temp.iNum[i] == '0')
                {
                    num0++;
                }
                else
                {
                    break;
                }
            }
            if (num0 > 0)
            {
                for (i = num0; i < len; i++)
                {
                    temp.iNum[i - num0] = temp.iNum[i];
                }
                temp.iNum[i - num0] = '\0';
            }
            else
            {
                temp.iNum[len] = '\0';
            }
        }
        else if (comp == -1) //先str2 - 本Bignum,再在前面加负号
        {
            // cout <<"fushu"<<endl;
            jie = '\0';
            len = strlen(iNum);
            len2 = strlen(str2.iNum);
            duo = len2 - len;
            pos = len2 - 1;
            for (i = len - 1; i >= 0; i--) // 1777
            {                              // 999
                if (iNum[i] > (str2.iNum[i + duo] - jie))
                {
                    k = '\12' + str2.iNum[i + duo] - iNum[i] - jie; // '\12'+str1.iNum[i+duo] -'0' - (str2.iNum[i]-'0')
                    jie = '\1';
                }
                else
                {
                    k = str2.iNum[i + duo] - iNum[i] - jie;
                    jie = '\0';
                }
                temp.iNum[pos] = k + '0';

                // cout << pos << ":"<<str2.iNum[i+duo]<<":"<< iNum[i]<< ":"<<temp.iNum[pos]<<endl;
                pos = pos - 1;
            }
            for (i = len2 - len - 1; i >= 0; i--) // 999 3 10011
            {
                if (str2.iNum[i] == '0' && jie == '\1')
                {
                    k = '\11'; //八进制11等于十进制9
                    jie = '\1';
                }
                else
                {
                    k = str2.iNum[i] - '0' - jie;
                    jie = '\0';
                }
                temp.iNum[pos] = k + '0';
                //  cout << pos << ":;"<<str2.iNum[i]<<":"<<temp.iNum[pos]<<endl;

                pos = pos - 1;
            }
            int num0 = 0; //去前面的0
            for (i = 0; i < len2; i++)
            {
                if (temp.iNum[i] == '0')
                {
                    num0++;
                }
                else
                {
                    break;
                }
            }
            // 000123456 len2=9 num0=3 -123456
            if (num0 > 1)
            {
                for (i = num0; i < len2; i++)
                {
                    temp.iNum[i - num0 + 1] = temp.iNum[i];
                }
                temp.iNum[0] = '-';
                temp.iNum[len2 - num0 + 1] = '\0';
            }
            else if (num0 == 1)
            {
                // cout << -1 << endl;
                temp.iNum[0] = '-';
                temp.iNum[len2] = '\0';
            }
            else
            {
                for (i = len2; i > 0; i--)
                {
                    temp.iNum[i] = temp.iNum[i - 1];
                }
                if (len2 < NUMLEN - 2)
                {
                    temp.iNum[0] = '-';
                    temp.iNum[len2 + 1] = '\0';
                }
                else
                {
                    temp.iNum[0] = '-';
                    temp.iNum[NUMLEN - 2] = 'E';
                    temp.iNum[NUMLEN - 1] = '\0';
                }
            }
        }
        else
        {
            temp.iNum[0] = '0';
            temp.iNum[1] = '\0';
        }
        return temp;
    }

    Bignum chen(const Bignum &str2) const //两个数大于等于0
    {
        /* Bignum temp; //返回值
         Bignum temp2; //str2 的副本
         Bignum temp3;  //本值
         Bignum temp4("1");
         Bignum temp5;
         unsigned int i;
         if(iNum[0] == 'E' || str2.iNum[0] == 'E')
         {
             temp.iNum[0] = 'E';
             temp.iNum[1] = '\0';
             return temp;
         }
         if(str2.iNum[0]== '0' && str2.iNum[1]== '\0')
         {
             temp.iNum[0] = '0';
             temp.iNum[1] = '\0';
             return temp;
         }
         for(i=0;i<=strlen(iNum);i++)
         {
             temp.iNum[i] = iNum[i];
         }
         if(str2.iNum[0]== '1' && str2.iNum[1]== '\0')
         {
             return temp;
         }
         temp3 = temp;
         for(i=0;i<=strlen(str2.iNum);i++)
         {
             temp2.iNum[i] = str2.iNum[i];
         }
         while(temp2.iNum[0]!='1' || temp2.iNum[1]!='\0')
         {
             temp = temp + temp3;
             temp2 = temp2 - temp4;
             }*/

        //模拟乘法步骤
        int i, k;
        int j;
        int e = 0;        //指数代表位数
        Bignum temp0;     //本数
        Bignum temp("0"); //返回值
        Bignum temp2;     //中间值
                          //    cout <<"start1= " << str2.iNum<< endl;
        if (iNum[0] == 'E' || iNum[NUMLEN - 2] == 'E' || str2.iNum[0] == 'E' || str2.iNum[NUMLEN - 2] == 'E')
        {
            temp.iNum[0] = 'E';
            temp.iNum[1] = '\0';
            return temp;
        }
        //     cout <<"start2= " << str2.iNum<< endl;

        for (i = 0; i < (int)strlen(iNum); i++)
        {
            temp0.iNum[i] = iNum[i];
        }
        //     cout <<"start3= " << str2.iNum<< endl;

        temp0.iNum[i] = '\0';
        //    cout <<"start4 for temp0=" << temp0.iNum << "str2="<< str2.iNum<<endl;

        for (i = strlen(str2.iNum) - 1; i >= 0; i--)
        {
            //中间值归零
            temp2.iNum[0] = '0';
            temp2.iNum[1] = '\0';
            if (str2.iNum[i] == '0')
            {
                //        cout <<"start 0  " << i <<endl;

                temp2.iNum[0] = '0';
                temp2.iNum[1] = '\0';
            }
            else if (str2.iNum[i] == '1')
            {
                //        cout <<"start 1  " << i <<endl;

                temp2 = temp0;
            }
            else if (str2.iNum[i] == '2')
            {
                //     cout <<"start 2  " << i <<endl;
                temp2 = temp0 + temp0;
            }
            else if (str2.iNum[i] == '3')
            {
                //     cout <<"start 3  " << i <<endl;
                temp2 = temp0 + temp0 + temp0;
            }
            else if (str2.iNum[i] == '4')
            {
                //    cout <<"start 4  " << i <<endl;
                temp2 = temp0 + temp0;
                temp2 = temp2 + temp2;
            }
            else if (str2.iNum[i] == '5')
            {
                //     cout <<"start 5  " << i <<endl;
                temp2 = temp0 + temp0;
                temp2 = temp2 + temp2;
                temp2 = temp2 + temp0;
            }
            else if (str2.iNum[i] == '6')
            {
                //   cout <<"start 6  " << i <<endl;
                temp2 = temp0 + temp0;
                temp2 = temp2 + temp0;
                temp2 = temp2 + temp2;
            }
            else if (str2.iNum[i] == '7')
            {
                //   cout <<"start 7  "<< i  <<endl;
                temp2 = temp0 + temp0;
                temp2 = temp2 + temp0;
                temp2 = temp2 + temp2;
                temp2 = temp2 + temp0;
            }
            else if (str2.iNum[i] == '8')
            {
                // cout <<"start 8  " << i <<endl;
                temp2 = temp0 + temp0;
                temp2 = temp2 + temp2;
                temp2 = temp2 + temp2;
            }
            else if (str2.iNum[i] == '9')
            {
                //  cout <<"start 9  " << i <<endl;
                temp2 = temp0 + temp0;
                temp2 = temp2 + temp2;
                temp2 = temp2 + temp2;
                temp2 = temp2 + temp0;
            }
            //   cout <<"start e " << temp2.iNum << endl;
            if (e > 0 && temp2.iNum[0] != '0')
            {
                if (temp2.iNum[0] != 'E' && temp2.iNum[NUMLEN - 2] != 'E')
                {
                    k = strlen(temp2.iNum);
                    //          cout <<" k=" << k <<endl;
                    if (e + k < NUMLEN - 2)
                    {
                        for (j = 0; j < e; j++)
                        {
                            temp2.iNum[k + j] = '0';
                        }
                        temp2.iNum[k + j] = '\0';
                    }
                    else
                    {
                        //  cout << "e="<<e<<" k="<<k<<endl;
                        temp2.iNum[NUMLEN - 2] = 'E';
                        temp2.iNum[0] = 'E';
                        temp2.iNum[NUMLEN - 1] = '\0';
                    }
                }
            }
            if (temp2.iNum[NUMLEN - 2] == 'E')
            {
                //越界了
                temp.iNum[NUMLEN - 2] = 'E';
                temp.iNum[0] = 'E';
                temp.iNum[NUMLEN - 1] = '\0';
                // cout << "temp2=" << temp2.iNum << "len="<<strlen(temp2.iNum) << endl;
                break;
            }
            else
            {
                temp = temp + temp2;
                if (temp.iNum[NUMLEN - 2] == 'E')
                {
                    // temp.iNum[NUMLEN-1]='E';
                    temp.iNum[0] = 'E';
                    temp.iNum[NUMLEN - 1] = '\0';
                    //  cout <<"temp ="<< temp.iNum <<endl;
                    break;
                }
            }
            //   cout << "temp2=" << temp2.iNum << "  temp=" << temp.iNum <<"  e="<<e << endl;
            e++;
        }

        return temp;
    }

    Bignum chu(const Bignum &str2) const //两个数大于等于0
    {
        Bignum temp;       //返回值
        Bignum temp0("5"); //试验值
        Bignum temp1;      //截取被除数长度
        Bignum yutemp;     //余数
        int k;
        int pos = 0; //得数位置
        int pos1;    //原被除数被计算位置
        int len = (int)strlen(iNum);
        int len2 = (int)strlen(str2.iNum);
        int len1; // temp1.iNum长度
        //   cout <<"iNum="<<iNum<<" str2="<< str2.iNum << endl;
        if (len < len2)

        {
            temp.iNum[0] = '0';
            temp.iNum[1] = '\0';
            return temp;
        }
        for (k = 0; k < len2; k++)
        {
            temp1.iNum[k] = iNum[k];
        }
        temp1.iNum[len2] = '\0';                        //这时k=len2。
        if (compareBignum(temp1.iNum, str2.iNum) == -1) //小于被除数，就算到下一位
        {
            if (len2 < len) // 012345
            {
                temp1.iNum[len2] = iNum[len2]; //这时k=len2。
                temp1.iNum[len2 + 1] = '\0';
                pos1 = len2;
            }
            else
            {
                temp.iNum[0] = '0';
                temp.iNum[1] = '\0';
                return temp;
            }
        }
        else
        {
            pos1 = len2 - 1; //这时k=len2。pos1从0算起，所以减1.
        }

        while (true)
        {

            // cout << "temp1=" << temp1.iNum << "str2=" << str2.iNum <<"yutemp="<<yutemp.iNum<< "temp=" << temp.iNum<<endl;
            while (true)
            {
                temp0.iNum[0] = '5';
                yutemp = temp1 - str2 * temp0;
                if (yutemp.iNum[0] == '-') // 5不足
                {
                    temp0.iNum[0] = '3';
                    yutemp = temp1 - str2 * temp0;
                    if (yutemp.iNum[0] == '-') // 3不足
                    {
                        temp0.iNum[0] = '2';
                        yutemp = temp1 - str2 * temp0;
                        if (yutemp.iNum[0] == '-') // 2不足
                        {
                            yutemp = temp1 - str2;
                            temp.iNum[pos] = '1';
                            temp.iNum[pos + 1] = '\0';
                            pos = pos + 1;
                            break;
                        }
                        else // 2有余
                        {
                            temp.iNum[pos] = '2';
                            temp.iNum[pos + 1] = '\0';
                            pos = pos + 1;
                            break;
                        }
                    }
                    else // 3足 5不足
                    {
                        temp0.iNum[0] = '4';
                        yutemp = temp1 - str2 * temp0;
                        if (yutemp.iNum[0] == '-') // 4不足
                        {
                            temp0.iNum[0] = '3';
                            yutemp = temp1 - str2 * temp0;
                            temp.iNum[pos] = '3';
                            temp.iNum[pos + 1] = '\0';
                            pos = pos + 1;
                            break;
                        }
                        else // 4有余
                        {
                            temp.iNum[pos] = '4';
                            temp.iNum[pos + 1] = '\0';
                            pos = pos + 1;
                            break;
                        }
                    }
                }
                else // 5足
                {
                    temp0.iNum[0] = '7';
                    yutemp = temp1 - str2 * temp0;
                    if (yutemp.iNum[0] == '-') // 7不足
                    {
                        temp0.iNum[0] = '6';
                        yutemp = temp1 - str2 * temp0;
                        if (yutemp.iNum[0] == '-') // 6不足
                        {
                            temp0.iNum[0] = '5';
                            yutemp = temp1 - str2 * temp0;
                            temp.iNum[pos] = '5';
                            temp.iNum[pos + 1] = '\0';
                            pos = pos + 1;
                            break;
                        }
                        else // 6有余
                        {
                            temp.iNum[pos] = '6';
                            temp.iNum[pos + 1] = '\0';
                            pos = pos + 1;
                            break;
                        }
                    }
                    else // 7足
                    {
                        temp0.iNum[0] = '8';
                        yutemp = temp1 - str2 * temp0;
                        if (yutemp.iNum[0] == '-') // 8不足
                        {
                            temp0.iNum[0] = '7';
                            yutemp = temp1 - str2 * temp0;
                            temp.iNum[pos] = '7';
                            temp.iNum[pos + 1] = '\0';
                            pos = pos + 1;
                            break;
                        }
                        else // 8有余
                        {
                            temp0.iNum[0] = '9';
                            yutemp = temp1 - str2 * temp0;
                            if (yutemp.iNum[0] == '-') // 9不足
                            {
                                temp0.iNum[0] = '8';
                                yutemp = temp1 - str2 * temp0;
                                temp.iNum[pos] = '8';
                                temp.iNum[pos + 1] = '\0';
                                pos = pos + 1;
                                break;
                            }
                            else // 9足
                            {
                                //  yutemp = temp1 - str2 * temp0;
                                temp.iNum[pos] = '9';
                                temp.iNum[pos + 1] = '\0';
                                pos = pos + 1;
                                break;
                            }
                        }
                    }
                }
            }

            //重新算被除数
            if (pos1 == len - 1)
            {
                // cout << "pos1 + len2 > len" << " pos1 =" << pos1 <<" len2=" <<len2 << " len=" <<len<<"pos="<< pos<< endl;
                // cout <<"2pos1 == len -1 ret=" << temp.iNum << endl;
                return temp;
            }
            if (yutemp.iNum[0] != '0') //余数不为0
            {
                for (k = 0; k < (int)strlen(yutemp.iNum); k++)
                {
                    //余数作为被除数的一部分
                    temp1.iNum[k] = yutemp.iNum[k];
                }
                len1 = strlen(temp1.iNum);
                pos1 = pos1 + 1;
                temp1.iNum[k] = iNum[pos1];
                temp1.iNum[k + 1] = '\0';

                while (compareBignum(temp1.iNum, str2.iNum) == -1) //小于被除数，就算到下一位
                {
                    if (pos1 == len - 1)
                    {
                        temp.iNum[pos] = '0';
                        temp.iNum[pos + 1] = '\0';
                        pos = pos + 1;
                        //       cout << "pos1 == len -1" << endl;
                        // cout <<"pos1 == len -1  ret="<<temp.iNum<<endl;
                        return temp;
                    }
                    else
                    {
                        temp.iNum[pos] = '0';
                        temp.iNum[pos + 1] = '\0';
                        pos = pos + 1;

                        pos1 = pos1 + 1;
                        k = k + 1;
                        temp1.iNum[k] = iNum[pos1];
                        temp1.iNum[k + 1] = '\0';
                    }
                }
            }
            else //余数是0  1110  11 100
            {
                //    cout << "temp="<<temp.iNum << " len=" << len <<" pos1="<< pos1 <<" temp1="<<temp1.iNum<<endl;
                //如果当前值为0
                pos1 = pos1 + 1;
                while (iNum[pos1] == '0')
                {
                    temp.iNum[pos] = '0';
                    temp.iNum[pos + 1] = '\0';
                    pos1 = pos1 + 1;
                    pos = pos + 1;
                }
                //   cout << "pos1=" <<pos1  <<"len=" <<len << endl;
                if (pos1 == len)
                {
                    //  cout <<"1pos1 ==  len ret="<<temp.iNum<<endl;
                    return temp;
                }

                for (k = 0; k < len2 - 1; k++)
                {
                    temp1.iNum[k] = iNum[pos1];
                    temp1.iNum[k + 1] = '\0';
                    pos1 = pos1 + 1;
                    temp.iNum[pos] = '0';
                    temp.iNum[pos + 1] = '\0';
                    pos = pos + 1;
                    if (pos1 == len)
                    {
                        //  cout <<"pos1 ==  len ret="<<temp.iNum<<endl;

                        return temp;
                    }
                }
                //    cout << "temp1.iNum=" <<temp1.iNum << " pos="<<pos<<endl;
                temp1.iNum[k] = iNum[pos1];
                temp1.iNum[k + 1] = '\0';
                pos1 = pos1 + 1;

                if (compareBignum(temp1.iNum, str2.iNum) == -1)
                {
                    //      cout <<"compareBignum(temp1.iNum,str2.iNum)==-1"<<endl;
                    if (pos1 == len)
                    {
                        temp.iNum[pos] = '0';
                        temp.iNum[pos + 1] = '\0';
                        return temp;
                    }
                    else // 1110111011  11
                    {
                        temp.iNum[pos] = '0';
                        temp.iNum[pos + 1] = '\0';
                        pos = pos + 1;

                        k = k + 1;
                        temp1.iNum[k] = iNum[pos1];
                        temp1.iNum[k + 1] = '\0';
                        pos1 = pos1 + 1;
                    }
                }
                pos1 = pos1 - 1;
            }

        } // while
        // temp.iNum[pos] = '\0';
        //   cout <<"ret="<<temp.iNum<<endl;
        return temp;
    }

    Bignum jia(const Bignum &str2) const
    {
        Bignum temp;
        if (iNum[0] == 'E' || str2.iNum[0] == 'E')
        {
            cout << "iNum[0]= E" << endl;
            temp.iNum[0] = 'E';
            temp.iNum[1] = '\0';
            temp.iNum[NUMLEN - 2] = 'E';
            temp.iNum[NUMLEN - 1] = '\0';
            return temp;
        }
        if (str2.iNum[NUMLEN - 2] == 'E' || iNum[NUMLEN - 2] == 'E')
        {

            cout << "str.iNum[NUMLEN -1]= E" << endl;

            temp.iNum[0] = 'E';
            temp.iNum[NUMLEN - 2] = 'E';
            temp.iNum[NUMLEN - 1] = '\0';
            return temp;
        }

        int i, pos, len, len2;
        char jin, k;
        len = strlen(iNum);
        len2 = strlen(str2.iNum);
        if (len2 >= len)
        {
            //    cout <<" len2 >= len" <<endl;
            int duo = len2 - len;
            jin = '\0';
            pos = len2 - 1;
            for (i = len - 1; i >= 0; i--)
            {
                // cout << "pos=" << pos << endl;
                k = jin + str2.iNum[i + duo] - '0' + iNum[i] - '0';
                if (k >= '\12') // 8进制12等于十进制10
                {
                    jin = '\1';
                    k = k - '\12';
                    temp.iNum[pos] = k + '0';
                }
                else
                {
                    jin = '\0';
                    temp.iNum[pos] = k + '0';
                }
                //  cout << pos << ":"<<str2.iNum[i+duo]<<":"<< iNum[i]<< ":"<<temp.iNum[pos]<<endl;
                pos = pos - 1;
            }
            for (i = len2 - len - 1; i >= 0; i--)
            {
                k = str2.iNum[i] - '0' + jin;
                if (k >= '\12')
                {
                    k = k - '\12';
                    temp.iNum[pos] = k + '0';
                    jin = '\1';
                }
                else
                {
                    temp.iNum[pos] = k + '0';
                    jin = '\0';
                }
                pos = pos - 1;
            }
            if (jin == '\1')
            {
                if (len2 < NUMLEN - 1)
                {

                    for (i = len2 - 1; i >= 0; i--)
                    {
                        temp.iNum[i + 1] = temp.iNum[i];
                    }
                    temp.iNum[0] = '1';
                    temp.iNum[len2 + 1] = '\0'; // 99 199
                }
                else
                {
                    temp.iNum[0] = 'E';
                    if (NUMLEN > 0)
                        temp.iNum[NUMLEN - 2] = 'E';
                    temp.iNum[NUMLEN - 1] = '\0';
                }
            }
            else
            {
                temp.iNum[len2] = '\0';
            }
            // 0123456789 len =10
            //      01234 len =5
            // pos=4
        }
        else // len2<len
        {
            //    cout <<"len2 < len" << endl;
            int duo = len - len2;
            jin = '\0';
            pos = len - 1;
            for (i = len2 - 1; i >= 0; i--)
            {
                // cout << "pos=" << pos << endl;
                k = jin + iNum[i + duo] - '0' + str2.iNum[i] - '0';
                if (k >= '\12') // 8进制12等于十进制10
                {
                    jin = '\1';
                    k = k - '\12';
                    temp.iNum[pos] = k + '0';
                    // cout << "j"<< temp.iNum[pos];
                }
                else
                {
                    jin = '\0';
                    temp.iNum[pos] = k + '0';
                    // cout << "w"<< temp.iNum[pos];
                }
                // cout << pos << ":"<<iNum[i+duo]<<":"<< str2.iNum[i]<< ":"<<temp.iNum[pos]<<endl;
                pos = pos - 1;
            }
            for (i = len - len2 - 1; i >= 0; i--)
            {
                k = iNum[i] - '0' + jin;
                if (k >= '\12')
                {
                    k = k - '\12';
                    temp.iNum[pos] = k + '0';
                    jin = '\1';
                }
                else
                {
                    temp.iNum[pos] = k + '0';
                    jin = '\0';
                }
                pos = pos - 1;
            }
            if (jin == '\1')
            {
                if (len < NUMLEN - 1)
                {
                    for (i = len - 1; i >= 0; i--)
                    {
                        temp.iNum[i + 1] = temp.iNum[i];
                    }
                    temp.iNum[0] = '1';
                    temp.iNum[len + 1] = '\0'; // 99 199
                }
                else
                {
                    temp.iNum[0] = 'E';
                    if (NUMLEN > 1)
                    {
                        temp.iNum[NUMLEN - 2] = 'E'; //越界符号
                        temp.iNum[NUMLEN - 1] = '\0';
                    }
                }
            }
            else
            {
                temp.iNum[len] = '\0';
            }
        }
        return temp;
    }

    void setValue(char ch, int pos)
    {
        iNum[pos] = ch;
    }
    char *getValue()
    {
        return iNum;
    }
    char getValue(int pos)
    {
        return iNum[pos];
    }
    void setch(char *ch)
    {
        int i;
        for (i = 0; i < (int)strlen(iNum); i++)
        {
            ch[i] = iNum[i];
        }
        ch[i] = '\0';
    }
};

/*
void pai()  //from:https://blog.csdn.net/weixin_31080559/article/details/117145673?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7Edefault-2.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7Edefault-2.no_search_link
{
//TDateTime t0 = Now();
clock_t start, finish;
 start = clock();
    double   duration;
const int ARRSIZE=10100, DISPCNT=10000; //定义数组大小，显示位数
char x[ARRSIZE], z[ARRSIZE]; //x[0] x[1] . x[2] x[3] x[4] .... x[ARRSIZE-1]
int a=1, b=3, c, d, Run=1, Cnt=0;
memset(x,0,ARRSIZE);
memset(z,0,ARRSIZE);
x[1] = 2;
z[1] = 2;
while(Run && (++Cnt<200000000))
{
//z*=a;
d = 0;
for(int i=ARRSIZE-1; i>0; i--)
{
c = z[i]*a + d;
z[i] = c % 10;
d = c / 10;
}
//z/=b;
d = 0;
for(int i=0; i<ARRSIZE-1; i++)
{
c = z[i]+d*10;
z[i] = c / b;
d = c % b;
}
//x+=z;
Run = 0;
for(int i=ARRSIZE-1; i>0; i--)
{
c = x[i] + z[i];
x[i] = c%10;
x[i-1] += c/10;
Run |= z[i];
}
a++;
b+=2;
}
string s;
printf("count %d\r\n", Cnt);
//s.cat_sprintf(_T("计算时间：%.3f 秒\r\n"), t);
printf("Pi=%d%d.", x[0], x[1]);
//for(int i=0; i<ARRSIZE-3;i++)
for(i=0; i<DISPCNT; i++){
{
if(i && ((i%100)==0))
s += ("\r\n");
s += (int)x[i+2];
printf("%d",x[i+2]);
}
printf("\n\n");
finish = clock();
duration = (double)(finish - start) / CLOCKS_PER_SEC;
printf( "%.3f seconds\n", duration );
return ;
}
*/
Bignum pi(int lenth); //计算π
int compareBignum(const char *str1, const char *str2)
{
    int ret;
    int i, len = strlen(str1);
    if (strlen(str1) == strlen(str2))
    {
        ret = 0;
        for (i = 0; i < len; i++)
        {
            if (str1[i] > str2[i])
            {
                ret = 1;
                break;
            }
            else if (str1[i] < str2[i])
            {
                //  cout <<"str1=" << str1[i] <<"str2=" <<str2[i] <<endl;
                ret = -1;
                break;
            }
        }
    }
    else if (strlen(str1) > strlen(str2))
    {
        ret = 1;
    }
    else
    {
        ret = -1;
    }
    return ret; // ret=-1:str1<str2; =0:str1==str2;1:str1>str2
}
Bignum pi(int lenth)
{
    // pi/2=1+1/3+1/3*2/5+1/3*2/5*3/7+.....
    // pi=2+2/3+2/3*2/5+2/3*2/5*3/7+.....
    Bignum temp;
    Bignum pilen;
    Bignum temp0; //算过的分数
    Bignum temp1; //分子
    Bignum temp2; //分母
    char fentmp[NUMLEN];
    int i;
    int n;
    int res = 4; //多算几位，以保精确。
    //cout << "pi........" << endl;
    if (lenth > NUMLEN - 1 - res)
    {
        lenth = NUMLEN - 1;
    }
    else
    {
        lenth = lenth + res;
    }
    temp.setValue('2', 0);
    pilen.setValue('1', 0);
    for (i = 1; i <= lenth; i++)
    {
        pilen.setValue('0', i);
        temp.setValue('0', i);
    }
    pilen.setValue('\0', i);
    temp.setValue('\0', i);
    temp1.setValue('2', 0);
    temp1.setValue('\0', 1);
    temp2.setValue('3', 0);
    temp2.setValue('\0', 1);
    //  cout <<"pilen" << pilen.getValue() << " temp2=" << temp2.getValue() << endl;
    temp0 = pilen * temp1 / temp2;
    temp = temp + temp0;
    //   cout <<"temp.getValue()="<<temp.getValue()<<endl;
    // n=2;
    for (n = 2; true; n++)
    {
        // if ((n % 100) == 0)
        // {
        //     cout << "now precision is " << n << endl;
        // }
        int k;
        itoa(n, fentmp, 10);
        //     cout <<"fentmp="<<fentmp<<endl;
        for (k = 0; k < (int)strlen(fentmp); k++)
        {
            temp1.setValue(fentmp[k], k);
        }
        temp1.setValue('\0', k);
        itoa(2 * n + 1, fentmp, 10);
        for (k = 0; k < (int)strlen(fentmp); k++)
        {
            temp2.setValue(fentmp[k], k);
        }
        temp2.setValue('\0', k);

        temp0 = temp0 * temp1 / temp2;
        temp = temp + temp0;
        if (temp0.getValue(0) == '0')
            break;
    }
    //cout << "now precision is " << n - 1 << "  decimal digit:" << lenth - res << endl;
    //  temp = temp + temp;
    return temp;
}
char *itoa(int num, char *str, int radix) //整数转字符串
{                                         /*索引表*/
    char index[] = "0123456789ABCDEF";
    unsigned unum; /*中间变量*/
    int i = 0, j, k;
    /*确定unum的值*/
    if (radix == 10 && num < 0) /*十进制负数*/
    {
        unum = (unsigned)-num;
        str[i++] = '-';
    }
    else
        unum = (unsigned)num; /*其他情况*/
    /*转换*/
    do
    {
        str[i++] = index[unum % (unsigned)radix];
        unum /= radix;
    } while (unum);
    str[i] = '\0';
    /*逆序*/
    if (str[0] == '-')
        k = 1; /*十进制负数*/
    else
        k = 0;

    for (j = k; j <= (i - 1) / 2; j++)
    {
        char temp;
        temp = str[j];
        str[j] = str[i - 1 + k - j];
        str[i - 1 + k - j] = temp;
    }
    return str;
}
int main()
{
    freopen("pi.out","w",stdout);
    char n1[NUMLEN];
    char op;
    char n2[NUMLEN];
    int k;
    // pi.........
    Bignum pizhi;
    // pizhi= pi(10,10);
    for (k = 10000; k < 10001; k = k + 1)
    {
        pizhi = pi(k);
        char ret[NUMLEN];
        pizhi.setch(ret);
        int n, len2 = strlen(ret);
        if (len2 > NUMLEN - 2)
            len2 = NUMLEN - 2;
        if (len2 > k + 1)
            len2 = k + 1;
        for (n = len2; n > 0; n--)
        {
            ret[n + 1] = ret[n];
        }
        ret[len2 + 1] = '\0';
        ret[1] = '.';
        cout << ret << endl;
    }
    return 0;
}