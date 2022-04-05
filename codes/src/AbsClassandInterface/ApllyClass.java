package AbsClassandInterface;

class ApllyClass extends AbsClass implements Interface{
    public void getArea(int length, int breadth) {
        System.out.println("The area of the rectangle is " + (length * breadth));
    }
    public void getPerimeter(int length, int breadth) {
        System.out.println("The area of the rectangle is " + (2*(length + breadth)));
    }
    void run(){System.out.println("running safely");}
}
