#define bottom 6 // bottom
#define top 7 // top
int x;
const int tmp = 70;
void setup{
    bottom.attach(6);
    top.attach(7);
}

void loop{
    x = map(analogRead(axis_x), 0, 1024, 20, 160);
    if (digitalRead(top) == 1){
        top.write(20);
        delay(tmp);
    } 
    else{
        top.write(160);
        delay(tmp);
    }
    bottom.write(x);
}
