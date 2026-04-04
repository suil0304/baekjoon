import haxe.io.Input;

using StringTools;

class Main {
    private static final R:Int = 31;
    private static final M:Int = 1234567891;
    public static function main():Void {
        var stdin:Input = Sys.stdin();
        var length:Int = Std.parseInt(stdin.readLine());
        var str:String = stdin.readLine();
        
        var sum:Int = 0;
        var power:Int = 1;
        for(i in 0...length) {
            sum = (sum + ((str.charCodeAt(i) - 97 + 1) * power)) % M;
            power = (power * R) % M;
        }
        
        Sys.println(sum);
    }
}