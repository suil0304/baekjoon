import haxe.io.Input;

// Haxe는 자체 속도가 느려서 안 풀려요
// 시간 초과가 뜨네
// 크로스-플랫폼으로 견뎌야만 했던 시간은...! 어쩌구

class Main {
    public static function main():Void {
        var stdin:Input = Sys.stdin();
        var n:Int = Std.parseInt(stdin.readLine());
        var counts:Array<Int> = [for(i in 0...10000) 0];

        for(i in 0...n) {
            var num:Int = Std.parseInt(stdin.readLine());
            counts[num - 1]++;
        }

        for(i in 0...n) {
            for(j in 0...counts[i]) {
                Sys.println(i + 1);
            }
        }

        stdin.close();
    }
}