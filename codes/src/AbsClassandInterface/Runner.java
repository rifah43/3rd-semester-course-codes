package AbsClassandInterface;

public class Runner {
    public static void main(String[] args) {
        ApllyClass r1 = new ApllyClass();
        r1.getArea(5, 6);
        r1.getPerimeter(5, 6);
        AbsClass obj = new ApllyClass();
        obj.run();
    }
}
