import java.io.*;
import java.util.*;

public class nothing {
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {

        // hihihijjhihi 1
        String str = scn.next();
        int i = scn.nextInt();
        System.out.println(countHI(str, 0, 0));
        String wow = removeHI(str, 0, "");
        System.out.println(wow.charAt(i));
        removeHI1(str, 0, "");
    }
    
    public static int countHI(String str, int idx, int count)
    {
        if(idx >= str.length())
            return count;
        
        if(str.charAt(idx) == 'h' && str.charAt(idx+1) == 'i')
        {
            count++;
            return countHI(str, idx+2, count);
        }
        else
        {
            return countHI(str, idx+1, count);
        }
    }
    
    public static String removeHI(String str, int idx, String ans)
    {
        if(idx >= str.length())
        {
            return ans;
        }
        
        if(str.charAt(idx) == 'h' && str.charAt(idx+1) == 'i')
        {
            idx++;
        }
        else
        {
            ans += str.charAt(idx);
        }
        
        return removeHI(str, idx+1, ans);
    }
    public static void removeHI1(String str, int idx, String ans)
    {
        if(idx >= str.length())
        {
            return ;
        }
        
        if(str.charAt(idx) == 'h' && str.charAt(idx+1) == 'i')
        {
            idx++;
        }
        else
        {
            System.out.print(str.charAt(idx));
        }
        
        removeHI1(str, idx+1, "");
        return ;
    }
}
// import java.io.*;
// import java.util.*;

// public class nothing {
//     public static Scanner scn = new Scanner(System.in);
//     public static void main(String[] args) {
//         String str = scn.next();
//         // int i = scn.nextInt();
//         String rec = replaceHI(str, 0, "");
//         System.out.print(rec);
//         // if(!rec.isEmpty())
//         // {
//         //     System.out.println(rec.charAt(i));
//         // }
//         // replaceHIpep(str, 0, "");
        
//     }
//     public static String replaceHI(String str, int idx, String ans)
//     {
//         if(idx >= str.length())
//         {
//             String stri = "";
//             return stri;
//         }
//         if(str.charAt(idx) == 'h' && str.charAt(idx+1) == 'i')
//         {
//             // idx++;
//             ans += "pep";
//         }
//         else
//         {
//             ans += str.charAt(idx);
//         }
//         replaceHI(str, idx+1, ans);
//         return ans; 
//     }
//     // public static void replaceHIpep(String str, int idx, String ans)
//     // {
//     //     if(idx >= str.length())
//     //     {
//     //         System.out.print(ans);
//     //         return;
//     //     }
//     //     if(str.charAt(idx) == 'h' && str.charAt(idx+1) == 'i')
//     //     {
//     //         idx++;
//     //         ans += "pep";
            
//     //     }
//     //     else
//     //     {
//     //         ans += str.charAt(idx);
//     //     }
//     //     replaceHIpep(str, idx+1, ans);
//     //     return; 
//     // }
// }