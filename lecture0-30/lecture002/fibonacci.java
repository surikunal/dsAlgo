import java.util.Scanner;

public class fibonacci{
        public static void main(String[] args){
            Scanner scn=new Scanner(System.in);
            int n,next=1,prev=0;
            System.out.print("which position in fibonacci series : ");
            n=scn.nextInt();

            int a=0;
            int b=1;
            
            if(n>=1){
                System.out.print(a + " ");
                if(n==1){
                    return;
                }
                if(n>=2){
                    System.out.print(b + " ");
                    if(n==2){
                        return;
                    }
                }
                int sum=0;
                for(int i=3;i<=n;i++)
                {
                    sum=a+b;
                    a=b;
                    b=sum;
                    System.out.print(sum + " ");
                }
                System.out.println();
                System.out.println(sum);


                  }

             

            }


        }
    