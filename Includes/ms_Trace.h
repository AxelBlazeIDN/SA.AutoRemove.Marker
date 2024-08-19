:ABMarker
    0DD0: gMobMenu = get_label_addr @gMobileMenu // android 
    0DD1: gMobMenu = get_func_addr_by_cstr_name gMobMenu // android 
    0DD0: i = get_label_addr @_ZN6CRadar13ms_RadarTraceE // android 
    0DD1: i = get_func_addr_by_cstr_name i // android 
    gMobMenu += 0x48
    0DD8: gMobMenu = read_mem_addr gMobMenu size 2 add_ib 0 // android     
    gMobMenu *= 0x28
    gMobMenu += i
    gMobMenu += 8
    0DD8: x = read_mem_addr gMobMenu size 4 add_ib 0 // android 
    gMobMenu += 4
    0DD8: y = read_mem_addr gMobMenu size 4 add_ib 0 // android 
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
