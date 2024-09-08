{$CLEO .csa}
jump @AutoRemoveMarker

script_name "AxelBlaze"

int gMobMenu, i, blip, AxelBlazexxx
float x, y
const z = 20

{$Include Includes\ms_RadarTrace.h}

:AutoRemoveMarker
    while true
        wait 500   
        if 
            ABMarker() 
        then
            if 
                locate_char_any_means_3d AxelBlazexxx sphere 0 in_sphere x y z radius 20.0 20.0 500.0
            then
                get_label_pointer gMobMenu = get_label_addr @gMobileMenu
                find_function_by_name gMobMenu = get_func_addr_by_cstr_name gMobMenu 
                gMobMenu += 0x48
                read_memory blip = read_mem_addr gMobMenu size 4 add_ib 0
                remove_blip blip    
                write_memory gMobMenu value 0 size 4 add_ib 0 protect 0 
            end
        end
    end
return
