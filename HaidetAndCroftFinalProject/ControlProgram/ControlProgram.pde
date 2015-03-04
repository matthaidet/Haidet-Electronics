import org.firmata.*;
import cc.arduino.*;

import ddf.minim.spi.*;
import ddf.minim.signals.*;
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
import ddf.minim.effects.*;

import de.voidplus.leapmotion.*;
import development.*;

import processing.serial.*;
import cc.arduino.*;

import controlP5.*;

Arduino arduino;

ControlP5 cp5;
Chart view;

Hand hand;
LeapMotion leap;

Textlabel overspeed;
Textlabel stall;
Textlabel connection1;
Textlabel connection2;

Minim minim;
AudioPlayer overspeedSound;
AudioPlayer stallSound;
AudioPlayer connectionBeep1;
AudioPlayer connectionBeep2;
AudioPlayer connectionBeep3;
AudioPlayer powerSound;

boolean power=false;

int     hand_id         ;
PVector hand_position  ;
PVector hand_stabilized  ;
PVector hand_direction ;
PVector hand_dynamics;
float   hand_roll;
float   hand_pitch ;
float   hand_yaw;
boolean hand_is_left;
boolean hand_is_right;
float   hand_grab;
float   hand_pinch ;
float   hand_time;
PVector sphere_position;
float   sphere_radius;


void setup() {
  size(500, 500, P3D);
  background(0);

  //leap inits
  leap = new LeapMotion(this);
  hand = leap.getHand(0);

  cp5 = new ControlP5(this);

  cp5.addSlider("Throttle")
    .setRange(0, 100)
      .setValue(0)
        .setPosition(100, 400)
          .setSize(200, 50);

  cp5.addKnob("Speed")
    .setRange(0, 255)
      .setValue(220)
        .setPosition(100, 280)
          .setRadius(50)
            .setNumberOfTickMarks(20)
              .setTickMarkLength(4)
                .snapToTickMarks(false)
                  .setColorForeground(color(255))
                    .setColorBackground(color(0, 160, 100))
                      .setColorActive(color(255, 0, 0));

  cp5.addKnob("Pitch")
    .setRange(-100, 100)
      .setValue(0)
        .setPosition(100, 160)
          .setRadius(50)
            .setNumberOfTickMarks(20)
              .setTickMarkLength(4)
                .snapToTickMarks(false)
                  .setColorForeground(color(255))
                    .setColorBackground(color(0, 160, 100))
                      .setColorActive(color(255, 255, 0));

  cp5.addKnob("Roll")
    .setRange(-100, 100)
      .setValue(0)
        .setPosition(100, 40)
          .setRadius(50)
            .setNumberOfTickMarks(20)
              .setTickMarkLength(4)
                .snapToTickMarks(false)
                  .setColorForeground(color(255))
                    .setColorBackground(color(0, 160, 100))
                      .setColorActive(color(255, 255, 0));

  view = cp5.addChart("view")
    .setPosition(250, 50)
      .setSize(200, 200)
        .setRange(-20, 20)
          .setView(Chart.LINE) // use Chart.LINE, Chart.PIE, Chart.AREA, Chart.BAR_CENTERED
            ;

  cp5.addToggle("power")
    .setPosition(400, 420)
      .setSize(50, 20)
        .setColorBackground(color(255, 0, 0))
          .setColorActive(color(0, 255, 0))
            .setColorForeground(color(255, 255, 0));

  overspeed = cp5.addTextlabel("overspeed")
    .setText("!Aircraft Overspeed!")
      .setPosition(300, 300)
        .setColorValue(color(100))
          .setFont(createFont("CopperplateGothic", 15))
            ;

  stall = cp5.addTextlabel("stall")
    .setText("!Stall Warning!")
      .setPosition(300, 320)
        .setColorValue(color(100))
          .setFont(createFont("CopperplateGothic", 15))
            ;

  connection1 = cp5.addTextlabel("connection1")
    .setText("No Arduino Connection")
      .setPosition(300, 340)
        .setColorValue(color(100))
          .setFont(createFont("CopperplateGothic", 15))
            ;

  connection2 = cp5.addTextlabel("connection2")
    .setText("No Controller Connection")
      .setPosition(300, 360)
        .setColorValue(color(100))
          .setFont(createFont("CopperplateGothic", 15))
            ;


  view.addDataSet("Wing");
  view.setColors("Wing", color(255, 0, 255), color(255, 0, 0));
  view.setData("Wing", new float[4]);

  view.setStrokeWeight(1.5);

  view.addDataSet("Altitude");
  view.setColors("Altitude", color(255), color(0, 255, 0));
  // view.setData("Altitude", new float[4]);


  //sounds setup
  minim = new Minim(this);

  stallSound = minim.loadFile("ring.wav");
  overspeedSound = minim.loadFile("alert.mp3");
  connectionBeep1 = minim.loadFile("Beep.wav");
  connectionBeep2 = minim.loadFile("Low.mp3");
  connectionBeep3 = minim.loadFile("High.mp3");

  stallSound.loop();
  overspeedSound.loop();
  connectionBeep2.loop();
  connectionBeep1.loop();
  
try {
    arduino = new Arduino(this, Arduino.list()[1], 57600);
    arduino.pinMode(3,arduino.OUTPUT);
    arduino.pinMode(5,arduino.OUTPUT);
} catch(ArrayIndexOutOfBoundsException e){
 connection1.setColor(color(255,0,0)); 
 println("ConnectArduino");
}

}

void draw() {
  for (Hand hand : leap.getHands ()) {

    hand_id          = hand.getId();
    hand_position    = hand.getPosition();
    hand_stabilized  = hand.getStabilizedPosition();
    hand_direction   = hand.getDirection();
    hand_dynamics    = hand.getDynamics();
    hand_roll        = hand.getRoll();
    hand_pitch       = hand.getPitch();
    hand_yaw         = hand.getYaw();
    hand_is_left     = hand.isLeft();
    hand_is_right    = hand.isRight();
    hand_grab        = hand.getGrabStrength();
    hand_pinch       = hand.getPinchStrength();
    hand_time        = hand.getTimeVisible();
    sphere_position  = hand.getSpherePosition();
    sphere_radius    = hand.getSphereRadius();
  }


  background(0);


//Leap motion inputs
  
  //try-catch prevents undesired crash
  try {
    if(leap.countHands() >0 ){
    cp5.getController("Pitch").setValue(hand_roll*1.75);
    cp5.getController("Roll").setValue(hand_pitch);
    cp5.getController("Throttle").setValue((450-hand_position.y)/4);
    }
  } 
  catch (NullPointerException e) {
    connection2.setColor(color(255,0,0));
  }



  cp5.getController("Speed").setValue(cp5.getController("Throttle").getValue()-cp5.getController("Pitch").getValue()/2);


//graphical wing view and altimeter
  view.unshift("Wing", cp5.getController("Pitch").getValue()/10);
  view.unshift("Altitude", -cp5.getController("Roll").getValue()/10);
  view.unshift("Altitude", cp5.getController("Roll").getValue()/10);


  //warning systems
  if (power==true) {

         try {
//      arduino.analogWrite(3, int(90-cp5.getController("Pitch").getValue()+(100+cp5.getController("Roll").getValue())));
//      arduino.analogWrite(5, int(90+cp5.getController("Pitch").getValue()+(100+cp5.getController("Roll").getValue())));
arduino.analogWrite(3, int(90+cp5.getController("Roll").getValue()+cp5.getController("Pitch").getValue()));
      arduino.analogWrite(5, int(90+cp5.getController("Roll").getValue()-cp5.getController("Pitch").getValue()));
      arduino.analogWrite(6, int(cp5.getController("Throttle").getValue())*5);
} catch(Exception e){
 connection1.setColor(color(255,0,0)); 
 connectionBeep1.unmute();
}
  
    
    
    
    //leap motion warnings
    try {
      if (leap.countHands()<=0) {
        connectionBeep2.unmute();
        connection2.setColor(color(255, 255, 0));
      } else {
        connectionBeep2.mute();
        connection2.setColor(color(100));
      }
    } 
    catch (NullPointerException e) {
      connection2.setColor(color(255, 0, 0));
    }

    //stall warnings
    if (cp5.getController("Speed").getValue() <= 0 && cp5.getController("Pitch").getValue() >= 0) {
      stall.setColor(color(255, 255, 0));
    } else {
      stall.setColor(color(100));
    }
    if (cp5.getController("Speed").getValue() <= 0 && cp5.getController("Pitch").getValue() >= 50) {
      stallSound.unmute();
      stall.setColor(color(255, 0, 0));
    } else {
      stallSound.mute();
    }

    //arduino warning systems   
   try { 
    arduino.analogRead(0);
    connection1.setColor(color(100));
    connectionBeep1.mute();
   } catch (Exception e) {
     try {
    arduino = new Arduino(this, Arduino.list()[1], 57600);
    arduino.pinMode(3,arduino.OUTPUT);
    arduino.pinMode(5,arduino.OUTPUT);
} catch(ArrayIndexOutOfBoundsException ex){
 connection1.setColor(color(255,0,0)); 
 connectionBeep1.unmute();
}
   }
    
    
    
    

    //overspeed warnings
    if (cp5.getController("Speed").getValue() >= 100) {
      overspeed.setColor(color(255, 255, 0));
    } else {
      overspeed.setColor(color(100));
    }
    if (cp5.getController("Speed").getValue() >= 135) {
      overspeedSound.unmute();
      overspeed.setColor(color(255, 0, 0));
    } else {
      overspeedSound.mute();
    }
  } 

  if (power==false) {
    stallSound.mute();
    overspeedSound.mute();
    connectionBeep1.mute();
    connectionBeep2.mute();
    connectionBeep3.mute();
    overspeed.setColor(color(100));
    stall.setColor(color(100));
    connection1.setColor(color(100));
    connection2.setColor(color(100));
  }
}
