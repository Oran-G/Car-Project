class motor() {
    public:
        int fpin;
        int bpin;
        int diameter;
        int rs;
        int going_forward = 0;
        int last
        motor(int f, int b, int d, int r) {
            fpin = f;
            bpin = b;
            diameter = d;
            rs = r;
        }
        void forward(int len) {
            going_forward =  (len / diameter) / rs
        }
        void backward(int len)
        
}
  



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}