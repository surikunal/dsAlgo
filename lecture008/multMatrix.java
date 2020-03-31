import java.util.Scanner;
public class multMatrix{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("enter rows and col value : ");
        int n = scn.nextInt();
        int m = scn.nextInt();
        int[][] arr = new int[n][m];
        System.out.println("enter 1st array : ");
        input(arr);
        System.out.println("enter rows and col : ");
        int p=scn.nextInt();
        int q=scn.nextInt();
        int [][] ar= new int[p][q];
        System.out.println("enter 2nd array : ");
        input(ar);
        multi(arr , n , m , ar , p , q);
        //print(arr);
    }
    public static void input(int [][] a){
        for(int i=0 ; i<a.length ; i++){
            for(int j=0 ; j<a[0].length ; j++){
                a[i][j]=scn.nextInt();
            }
        }
       
    }
    public static void multi(int [][] a, int n , int m , int [][] b , int p ,int q){
        // int n=a.length;
        // int m=a[0].length;
        // int p=b.length;
        // int q=b[0].length;
        if(m==p){
            int[][] res=new int[n][q];
            for(int i=0 ; i<a.length ; i++){
                for(int j=0 ; j<b[0].length ; j++){
                   // res[i][j]=0;
                    for(int k=0 ; k<m ; k++){
                        res[i][j]+=a[i][k]*b[k][j];
                    }
                }
            }
            System.out.print("multiplied matrix is ");
            print(res);
        }
        else{
            System.out.print("matrix cannot be multiplied");
        }
        
        
    }
    public static void print(int [][] a){
        for(int i=0 ; i<a.length ; i++){
            System.out.println();
            for(int j=0 ; j<a[0].length ; j++){
                System.out.print(a[i][j]+ " ");
            }
        }
        
    }

}
