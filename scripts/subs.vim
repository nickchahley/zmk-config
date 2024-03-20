" swap ctl and alt (ex. homerow mods)
s/CTL/AALLTT/
s/ALT/CTL/
s/AALLTT/ALT/

" replace with unshifted (us_key)
'<,'>s/\v(&kp )(\w+)/&us_\L\2/g

" replace with trns ___
