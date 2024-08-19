:ABMarker
    get_label_pointer gMobMenu = get_label_addr @gMobileMenu   
    find_function_by_name gMobMenu = get_func_addr_by_cstr_name gMobMenu   
    get_label_pointer i = get_label_addr @_ZN6CRadar13ms_RadarTraceE   
    find_function_by_name i = get_func_addr_by_cstr_name i   
    gMobMenu += 0x48
    read_memory gMobMenu = read_mem_addr gMobMenu size 2 add_ib 0       
    gMobMenu *= 0x28
    gMobMenu += i
    gMobMenu += 8
    read_memory x = read_mem_addr gMobMenu size 4 add_ib 0   
    gMobMenu += 4
    read_memory y = read_mem_addr gMobMenu size 4 add_ib 0   
    if and
    x <> 0.0
    y <> 0.0
return

:gMobileMenu
hex
    "gMobileMenu" 00
end

:_ZN6CRadar13ms_RadarTraceE
hex
    "_ZN6CRadar13ms_RadarTraceE" 00
end
