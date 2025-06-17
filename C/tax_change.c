# include<stdio.h>
# include<stdlib.h>
# include<math.h>
int main()
{
    double o_tax,m_tax,f_tax;

    scanf("%lf",&o_tax);
    m_tax = o_tax-3500.0;
        if(m_tax <= 0)
            {printf("���ý�˰");goto end;}
        else if(m_tax <= 1500 && m_tax > 0)
            f_tax = m_tax * 0.01; 
        else if(m_tax <= 4500 && m_tax > 1500)
            f_tax = m_tax * 0.1 - 105;
        else if(m_tax <= 9000 && m_tax > 4500)
            f_tax = m_tax * 0.2 - 555;
        else if(m_tax <= 35000 && m_tax > 9000)
            f_tax = m_tax * 0.25 -1005;
        else if(m_tax <= 55000 && m_tax > 35000)
            f_tax = m_tax * 0.3 -2755;
        else if(m_tax <= 80000 && m_tax > 55000)
            f_tax = m_tax * 0.35 - 5505;
        else
            f_tax = m_tax * 0.45 - 13505;
        printf("%.2lf",f_tax);

    end :
    system("pause");
    return 0;
}

