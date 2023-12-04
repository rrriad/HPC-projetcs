
set terminal png size 800,600
set style data histograms
set style histogram clustered
set datafile separator ';'
set style fill solid border -1
set boxwidth 0.8 relative
set xtics rotate by -45
set ytics nomirror
set ylabel "MiB/s"

set ytics 
set yrange [0:*]




datafile1 = 'clang0.txt'
datafile2 = 'clang1.txt'
datafile3 = 'clang2.txt'
datafile4 = 'clang3.txt'


datafile7 = 'gcc0.txt'
datafile8 = 'gcc1.txt'
datafile9 = 'gcc2.txt'
datafile10 = 'gcc3.txt'


set output 'comparaison_entre_flags_clang.png'
plot \
    datafile1 every ::1 using 11:xtic(1) t "clang-flag -O0" lc rgb "#AD7FBF", \
    datafile2 every ::1 using 11:xtic(1) t "clang-flag -O1" lc rgb "#59895C",\
    datafile3 every ::1 using 11:xtic(1) t "clang-flag -O2" lc rgb "#6DB0D9",\
    datafile4 every ::1 using 11:xtic(1) t "clang-flag -O3" lc rgb "#EEB210"

set output 'comparaison_entre_flags_GCC.png'
plot \
    datafile7 every ::1 using 11:xtic(1) t "gcc-flag -O0" lc rgb "#AD7FBF", \
    datafile8 every ::1 using 11:xtic(1) t "gcc-flag -O1" lc rgb "#59895C",\
    datafile9 every ::1 using 11:xtic(1) t "gcc-flag -O2" lc rgb "#6DB0D9",\
    datafile10 every ::1 using 11:xtic(1) t "gcc-flag -O3" lc rgb "#EEB210"
