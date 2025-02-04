wagenHoehe = 220;
wagenBreite = 200;
wagenLaenge = 400;

SolarUnitYawRingHight = 10;
SolarUnitYawRingRadius = 20;

// wagen primitive
cube([wagenBreite,wagenLaenge,wagenHoehe]);

// translate to roof center
translate([wagenBreite/2,wagenLaenge/2,wagenHoehe + SolarUnitYawRingHight/2]) {
    // movement ring for pannel assembly yaw
    cylinder(h = SolarUnitYawRingHight, r= SolarUnitYawRingRadius, center = true);
    // solar pannel placeholder (SolarUnitSolarPanel)
    translate([10,-100,5]) {
        cube([10,200,100]);
    }
     // motor assmbly for yaw(SolarUnitYawMovementBox)
    translate([-15,-10,5]) {
        cube([10,20,10]);
    }
    hi=10;
    rad = 40;
    dif = 10;
    // quater ring for Pitch (SolarUnitPitchMovementRing)
    translate([rad/2, 0, 0]) {
        rotate([90,0,180]) {
            intersection(){
                difference() {    
                    cylinder(h=hi, r=rad, center=true);
                    cylinder(h=hi+1, r=rad-dif, center=true);
                }
                translate([0,0,-hi/2-1]){
                    cube([rad,rad,hi+2]);
                }
            }
        }
    }
}