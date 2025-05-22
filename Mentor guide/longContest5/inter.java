interface a{
    int number = 10;
    void run();
}

class b implements a{
    @Override
    void run(){
        System.out.println("Running");
    }
}