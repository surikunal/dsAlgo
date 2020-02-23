public class dynamicStack extends stack {
    dynamicStack() {
        super();
    }

    dynamicStack(int size) {
        super(size);
    }

    dynamicStack(int[] arr) {
        super(arr);
    }

    @Override
    public void push(int data) {
        if (this.tos + 1 == st.length) {
            int[] temp = st;
            st = new int[2 * st.length];

            for (int i = 0; i < temp.length; i++) {
                st[i] = temp[i];
            }
        }

        super.push(data);
    }
}