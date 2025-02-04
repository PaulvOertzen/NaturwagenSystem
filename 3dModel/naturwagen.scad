wagenHoehe = 220;
wagenBreite = 200;
wagenLaenge = 400;
wagenWallThickness = 10;

SolarUnitYawRingHight = 10;
SolarUnitYawRingRadius = 20;

SolarUnitPitchRingHight = 10;
solarUnitPitchRingRadius = 40;
SolarUnitPitchRingThickness = 20;

windowHight = 100;
windowWidth = 70;

doorWidth = 90;
doorHight = 200;

// wagen primitive
difference() { 
    difference() {
        cube([wagenBreite, wagenLaenge, wagenHoehe]);
        translate([wagenWallThickness, wagenWallThickness, wagenWallThickness]) {
            cube([wagenBreite - 2* wagenWallThickness,wagenLaenge - 2* wagenWallThickness, wagenHoehe - 2* wagenWallThickness]);
        }
    }
    //window
    translate([wagenBreite-wagenWallThickness-1, wagenLaenge/2 -windowWidth/2, wagenHoehe/2-windowHight/2]) {
        cube([wagenWallThickness+2, windowWidth, windowHight]);
    }
    //door
    translate([-1, wagenLaenge/2 -doorWidth/2, wagenHoehe/2-doorHight/2]) {
        cube([wagenWallThickness+2, doorWidth, doorHight]);
    }
}

// cube([wagenBreite,wagenLaenge,wagenHoehe]);

// translate to roof center
translate([wagenBreite/2,wagenLaenge/2,wagenHoehe + SolarUnitYawRingHight/2]) {
    // movement ring for pannel assembly yaw
    cylinder(h = SolarUnitYawRingHight, r= SolarUnitYawRingRadius, center = true);

    // solar pannel placeholder (SolarUnitSolarPanel)
    translate([SolarUnitYawRingRadius-20,-100,5]) {
        cube([10,200,100]);
    }
     // motor assmbly for yaw(SolarUnitYawMovementBox)
    translate([0,SolarUnitYawRingRadius/2,SolarUnitYawRingHight/2]) {
        cube([10,20,20]);
    }
    // motor assemblyfor pitch(SolarUnitPitchMovementBox)
    translate([-solarUnitPitchRingRadius/2 ,SolarUnitPitchRingHight/2,SolarUnitYawRingHight/2]) {
        cube([20,20,10]);
    } 
    // solar position esp enclosure
    translate([0,-10,105]) {
        cube([30,20,20]);
    }

    // quater ring for Pitch (SolarUnitPitchMovementRing) / villeicht besser ein kniehebel...?
    translate([solarUnitPitchRingRadius/2, 0, 0]) {
        rotate([90,0,180]) {
            intersection(){
                difference() {    
                    cylinder(h=SolarUnitPitchRingHight, r=solarUnitPitchRingRadius, center=true);
                    cylinder(h=SolarUnitPitchRingHight+1, r=solarUnitPitchRingRadius-SolarUnitPitchRingThickness, center=true);
                }
                translate([0,0,-SolarUnitPitchRingHight/2-1]){
                    cube([solarUnitPitchRingRadius,solarUnitPitchRingRadius,SolarUnitPitchRingHight+2]);
                }
            }
        }
    }
}