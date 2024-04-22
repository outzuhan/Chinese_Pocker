//
//  main.cpp
//  s1102005
//
//  Created by 歐姿含 on 2022/1/10.
//

#include<iostream>
#include <iomanip>
#include <algorithm>

int i;
using namespace std;

int main(int argc, const char * argv[])
    {
    string num;
    num = argv[1];
    int A[13];
    int total=13;
    int i;
    int carry = 0;
    int step = 0;
    
    
    for(i=0;i<num.size();i++){
        if(num[i]==','){
            carry = 0;
            step++;
    }
    else{
        carry++;
        if(carry==2){
            A[step]=A[step]*10+num[i]-48;
            
        }
        else A[step] = num[i]-48;
    }
}
    
    
        int card[13] = { 0 };
        int icard[13] = { 0 };

        int front[3] = { 0 };
        int mid[5] = { 0 };
        int back[5] = { 0 };

        int finally[13] = { 0 };

        
        
        int a[13] = { 0 };
        int one[13] = { 0 };
        int Xone[13] = { 0 };

        int pair1[13] = { 0 };
        int Xpair[13] = { 0 };

        int three[13] = { 0 };
        int Xthree[13] = { 0 };

        int four[13] = { 0 };
        int Xfour[13] = { 0 };

    
        
    for (i = 0; i < 13; i++) {
        card[i] = A[i];
    }
    
    for (i = 0; i < 13; i++) {
        a[i] = card[i];
    }

        for (int i = 0; i < 13; i++)
        {
            icard[i] = a[i];
        }
    
        
        for (int i = 0; i < 13; i++) {
            icard[i] = icard[i] % 13;
            if (icard[i] == 0)
                icard[i] = 13;
        }
    
    
        for (int i = 12; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (icard[j] > icard[j + 1]) {
                    int tmp;
                    tmp = icard[j];
                    icard[j] = icard[j + 1];
                    icard[j + 1] = tmp;
                    tmp = card[j];
                    card[j] = card[j + 1];
                    card[j + 1] = tmp;
                }
            }
        }

        int f = 0;
        for (int i = 0; i < 13; i++) {

            if (icard[i] == 1)
            {
                f++;
            }
        }
    
     
        for (int i = 0; i < f; i++) {
            int tmp = icard[0];
            for (int j = 0; j < 12; j++) {
                icard[j] = icard[j + 1];
            }
            icard[12] = tmp;
            tmp = card[0];
            for (int j = 0; j < 12; j++) {
                card[j] = card[j + 1];
            }
            card[12] = tmp;
        }
 

       
        int n = 0;
        if (icard[0] != icard[1]) {
            one[n] = icard[0];
            Xone[n] = card[0];
            n++;
        }
        for (int i = 1; i < 13; i++) {
            if ((icard[i] != icard[i + 1]) && (icard[i] != icard[i - 1])) {
                one[n] = icard[i];
                Xone[n] = card[i];
                n++;
            }
        }

        
     
        n = 0;
        for (int i = 0; i < 13; i++) {
            if (icard[i] == icard[i + 1] && icard[i + 1] == icard[i + 2] && icard[i + 2] == icard[i + 3]) {
                for (int j = 0; j < 4; j++) {
                    four[n] = (icard[i + j]);
                    Xfour[n] = (card[i + j]);
                    icard[i + j] = 0;
                    n++;
                }

            }
        }


        n = 0;
        for (int i = 0; i < 13; i++)
        {
            if (icard[i] == icard[i + 1] && icard[i + 1] == icard[i + 2] && icard[i + 2] != icard[i + 3]) {
                if (icard[i] != 0) {
                    for (int j = 0; j < 3; j++) {
                        three[n] = (icard[i + j]);
                        Xthree[n] = (card[i + j]);
                        icard[i + j] = 0;
                        n++;
                    }
                }
            }
        }

        n = 0;
        for (int i = 0; i < 13; i++) {
            if (icard[i] == icard[i + 1]) {
                if (icard[i] != 0) {
                    for (int j = 0; j < 2; j++) {
                        pair1[n] = (icard[i + j]);
                        Xpair[n] = (card[i + j]);
                        n++;
                    }
                }
            }
        }


        int s = 0;
        int p = 0;

        if (Xfour[4] > 0) {
            for (int i = 0; i < 4; i++) {
                back[i] = Xfour[i + 4];
                Xfour[i + 4] = 0;
            }
            if (Xone[s] > 0) {
                back[4] = Xone[s];
                Xone[s] = 0;
                s++;
            }
            else {
                back[4] = Xpair[p];
                Xpair[p] = 0;
                p++;
            }
        }
        
        if (Xfour[0] != 0) {
            if (back[0] == 0) {
                for (int i = 0; i < 4; i++) {
                    back[i] = Xfour[i];
                    Xfour[i] = 0;
                }
                if (Xone[s] != 0) {
                    back[4] = Xone[s];
                    Xone[s] = 0;
                    s++;
                }
                else {
                    back[4] = Xpair[p];
                    Xpair[p] = 0;
                    p++;
                }

            }
            else if (mid[0] == 0) {

                for (int i = 0; i < 4; i++) {
                    mid[i] = Xfour[i];
                    Xfour[i] = 0;
                }
                if (Xone[s] != 0) {
                    mid[4] = Xone[s];
                    Xone[s] = 0;
                    s++;
                }
                else {
                    mid[4] = Xpair[p];
                    Xpair[p] = 0;
                    p++;
                }

            }
        }

        if (Xthree[3] > 0 && Xpair[2] > 0)
        {
            if (back[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    back[i] = Xthree[i + 3];/
                    Xthree[i + 3] = 0;
                }
                for (int i = 0; i < 2; i++) {
                    back[i + 3] = Xpair[i + 3];
                    Xpair[i + 3] = 0;
                }
            }

            else if (mid[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    mid[i] = Xthree[i+3];
                    Xthree[i+3] = 0;
                }
                for (int i = 0; i < 2; i++) {
                    mid[i + 3] = Xpair[i];
                    Xpair[i] = 0;
                }
            }
        }

        if (Xthree[0] > 0 && Xpair[0] > 0) {
            if (back[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    back[i] = Xthree[i];
                    Xthree[i] = 0;
                }
                for (int i = 0; i < 2; i++) {
                    back[i + 3] = Xpair[i];
                    Xpair[i] = 0;
                }
            }
        
            else if (mid[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    mid[i] = Xthree[i + 3];
                    Xthree[i + 3] = 0;
                }
                for (int i = 0; i < 2; i++) {
                    mid[i + 3] = Xpair[i];
                    Xpair[i] = 0;
                }
            }
        }
      
        if (Xthree[3] > 0)
        {
            if (back[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    back[i] = Xthree[i + 3];
                    Xthree[i + 3] = 0;
                }
               

            }
            else if (mid[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    mid[i] = Xthree[i + 3];
                    Xthree[i + 3] = 0;
                }
            }
        }
        
        if (Xthree[0] > 0)
        {
            if (back[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    back[i] = Xthree[i];
                    Xthree[i] = 0;
                }

            }
            else if (mid[0] == 0) {
                for (int i = 0; i < 3; i++) {
                    mid[i] = Xthree[i];
                    Xthree[i] = 0;
                }
            }
        }
    
        
        int b[13] = { 0 };
        for (int i = 0; i < 13; i++) {
            b[i] = Xpair[12 - i];
        }

        for (int i = 0; i < 13; i++) {
            Xpair[i] = b[i];
        }

        
    int k = 0;
    f = 0;
    for (int i = 0; i < 13; i++) {
        if (Xpair[i] > 0) {
            k++;
        }
        if (Xpair[i] == 0 && k == 0)
        {
            f++;
        }
    }
    
    if (k > 0) {
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < 12; j++) {
                Xpair[j] = Xpair[j + 1];
            }
            Xpair[12] = 0;
        }
    }

    
    
        int t = 0;
        for (int i = 0; i < 10; i = i + 2) {
            if (Xpair[i] > 0) {
                t++;
            }
        }
        p = 0;
        if (t == 5)
        {
            if (back[0] == 0)
            {
                for (int i = 0; i < 4; i++) {
                    back[i] = Xpair[p];
                    p++;
                }
                for (int i = 0; i < 4; i++) {
                    mid[i] = Xpair[p];
                    p++;
                }
                for (int i = 0; i < 2; i++) {
                    front[i] = Xpair[p];
                    p++;
                }
            }

        }
        if (t == 4)
        {
            if (back[0] == 0)
            {
                for (int i = 0; i < 4; i++) {
                    back[i] = Xpair[p];
                    p++;
                }
                for (int i = 0; i < 2; i++) {
                    mid[i] = Xpair[p];
                    p++;
                }
                for (int i = 0; i < 2; i++) {
                    front[i] = Xpair[p];
                    p++;
                }
            }
           
        }
        if (t == 3)
        {
            if (back[0] == 0)
            {
                for (int i = 0; i < 4; i++) {
                    back[i] = Xpair[p];
                    p++;
                }
                for (int i = 0; i < 2; i++) {
                    mid[i] = Xpair[p];
                    p++;
                }
               
            }
            else if (mid[0] == 0) {
                for (int i = 0; i < 4; i++) {
                    mid[i] = Xpair[p];
                    p++;
                }
                for (int i = 0; i < 2; i++) {
                    front[i] = Xpair[p];
                    p++;
                }
            }
        }
        if (t == 2)
        {
            if (back[0] == 0)
            {
                for (int i = 0; i < 4; i++) {
                    back[i] = Xpair[p];
                    p++;
                }
            }
            else if (mid[0] == 0) {
                for (int i = 0; i < 4; i++) {
                    mid[i] = Xpair[p];
                    p++;
                }
              
            }
        }
        if (t == 1)
        {
            if (back[0] == 0)
            {
                for (int i = 0; i < 2; i++) {
                    back[i] = Xpair[p];
                    p++;
                }
               
            }
            else if (mid[0] == 0) {
                for (int i = 0; i < 2; i++) {
                    mid[i] = Xpair[p];
                    p++;
                }
            }
            else {
                for (int i = 0; i < 2; i++) {
                    front[i] = Xpair[p];
                    p++;
                }
            }
        }
    
      
        for (int i = 0; i < 3; i++)
        {
            if (front[i] == 0) {
                front[i] = Xone[s];
                s++;
            }
        }
        
        for (int i = 0; i < 5; i++)
        {
            if (mid[i] == 0) {
                mid[i] = Xone[s];
                s++;
            }
        }
        
        for (int i = 0; i < 5; i++)
        {
            if (back[i] == 0) {
                back[i] = Xone[s];
                s++;
            }
        }


        
        for (int i = 0; i < 3; i++)
        {
            finally[i] = front[i];
        }
        for (int i = 3; i < 8; i++)
        {
            finally[i] = mid[i - 3];
        }
        for (int i = 8; i < 13; i++)
        {
            finally[i] = back[i - 8];
        }
       
    for (i = 0; i < 12; i++) {

        cout<<finally[i]<<','; 
    }
    cout<<finally[i];
    cout<<endl;
    }


