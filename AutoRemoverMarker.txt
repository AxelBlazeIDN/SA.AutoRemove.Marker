{$CLEO .csa}
jump @RemoveMarker

script_name "AxelBlaze"

{$Include Includes/FRadarTrace.h} // FRadarTrace = FunctionRadarTrace

int gMobMenu, i, blip
float x, y
const z = 20

:RemoveMarker
    while true
        wait 500   
        if 
            ABMarker() 
        then
            if 00FE:   actor $PLAYER_ACTOR sphere 0 in_sphere x y z radius 20.0 20.0 500.0
            then
                0DD0: gMobMenu = get_label_addr @gMobileMenu // android 
                0DD1: gMobMenu = get_func_addr_by_cstr_name gMobMenu // android 
                gMobMenu += 0x48
                0DD8: blip = read_mem_addr gMobMenu size 4 add_ib 0 // android 
                remove_blip blip    
                0DD9: write_mem_addr gMobMenu value 0 size 4 add_ib 0 protect 0 // android   
            end
        end
    end
return

{$Include Includes/LRadarTrace} // LRadarTrace = LableRadarTrace
