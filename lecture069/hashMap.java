import java.util.LinkedList;

public class hashMap {

    public class Node {
        Integer key;
        Integer value;

        public Node(Integer key, Integer value) {
            this.key = key;
            this.value = value;
        }

        // ? toString is used to override the syso function
        // ? now syso will print this return statement instead of simple string
        @Override
        public String toString() {
            return this.key + "=" + this.value;
        }
    }

    private int size = 0;
    private LinkedList<Node>[] buckets = new LinkedList[10]; // int[] buckets = new int[];

    public hashMap() { // here we are making new linkedlist at every positoin
        reAssign();
    }

    // * is it used to simply fill the hashmap with required elements
    private void reAssign() {
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>();
        }
        this.size = 0; // we have to make it 0, because in put function we are keep on increasing the
                       // size, and that will be wrong (because we want our size to again start from 0)
    }

    // ? to override syso for hashmap class
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{");

        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i].size() > 0) {

                LinkedList<Node> group = buckets[i]; // * thats how we get the group (on which group we want to search)
                int size = group.size();

                while (size-- > 0) {
                    Node tempNode = group.getFirst();
                    sb.append(tempNode + ",");
                    group.addLast(group.removeFirst());
                }
            }
        }

        sb.deleteCharAt(sb.length() - 1); // that how we are deleting extra "," in the last
        // .erase in cpp
        sb.append("}");
        return sb.toString();
    }

    public int size() {
        return this.size();
    }

    private Node foundInGroup(LinkedList<Node> group, Integer key) {
        if (group == null)
            return null;

        Node rn = null;
        int size = group.size();
        while (size-- > 0) {
            Node tempNode = group.getFirst(); // get first element
            if (tempNode.key == key) { // checking that if this is my elemnet or not
                rn = tempNode;
                break;
            }
            group.addLast(group.removeFirst()); // if not then add that element to the last and continues
        }
        return rn;
    }

    // hashcode

    // ? this is going to decide that which we are going to visit
    public int myGroup(Integer key) {
        return myHashCode(key) % buckets.length; // by % this hashcode is now in the length of buckets always
    }

    public int myHashCode(Integer key) { // * anything can be used is "int" but key must be "Ineteger", so that it can
                                         // * store any type of value
        int val = key.hashCode();
        return Math.abs(val); // hashcode returns the address of key
    }
    /*
     * 
     * or we can also write only one funtoin like
     * 
     * public int myGroup(Integer key) { int val = key.hashCode(); return
     * Math.abs(val) % buckets.length; }
     * 
     */

    public void put(Integer key, Integer value) {
        int code = myGroup(key);
        LinkedList<Node> group = buckets[code];
        /*
         * if group is comming null then if (group == null) { buckets[code] = new
         * LinkedList<>(); }
         */
        Node rn = foundInGroup(group, key);

        if (rn != null) {
            rn.value = value;
        }

        else {
            Node node = new Node(key, value);
            group.addLast(node);
            this.size++;

            double lambda = group.size() * 1.0 / buckets.length; // by multiplying with 1.0 group.size() will become
                                                                 // integer, otherwise it is a decimal number
            if (lambda >= 0.3) { // 0.3 is our wish (thats how we decide that a single linkedlist will have how
                                 // many values)
                System.out.println("Rehas: " + group.size());
                rehash(); // * thats how are going to increase the length of linkedlist when ll is
                          // * full(rate of increase)
            }
        }
    }

    // ? this function is making a new hashmap again , when the old one is full
    public void rehash() {
        LinkedList<Node>[] oldBuckets = buckets; // new array of linkedlist
        buckets = new LinkedList[oldBuckets.length * 2]; // we decided the new bucket to be double size
        reAssign(); // this function will again assign the linkedlist to every box of array

        // now we again have to do the same work as toString, bcz we almost making a new
        // hashmap
        for (int i = 0; i < oldBuckets.length; i++) {
            if (oldBuckets[i].size() > 0) {
                LinkedList<Node> group = oldBuckets[i];
                int size = group.size();

                while (size-- > 0) {
                    Node tnode = group.removeFirst();
                    put(tnode.key, tnode.value);
                }
            }
        }
    }

    public Integer get(Integer key) {
        int code = myGroup(key); // return the address of linked list required
        LinkedList<Node> group = buckets[code]; // now we have assigned the linkedlist
        Node rn = foundInGroup(group, key); // now remove node have required key

        return rn == null ? null : rn.value;
    }

    public Node remove(Integer keys) {
        int code = myGroup(keys);
        LinkedList<Node> group = buckets[code];
        Node rn = foundInGroup(group, keys);

        if (rn != null) {
            this.size--;
            return group.removeFirst();
        } else {
            System.out.println("ElementNotFound: -1");
        }
        return rn;
    }

    public boolean containsKey(Integer key) {
        int code = myGroup(key);
        LinkedList<Node> group = buckets[code];
        Node rn = foundInGroup(group, key);

        return rn != null ? true : false;
    }
}