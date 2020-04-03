// import java.util.HashMap;
//* we are making our own hashmap so dont import java wala hashmap
public class client {
    public static void main(String[] args) {
        // HashMap map = new HashMap();

        hashMap map = new hashMap();
        map.put(10, 100);
        map.put(20, 110);
        map.put(30, 120);
        map.put(40, 130);
        map.remove(20);
        System.out.println(map.get(10));
        System.out.println(map.get(20));
        System.out.println(map);        //its a fact that hashmap always generate values randomly
    }
}