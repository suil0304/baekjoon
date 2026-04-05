import haxe.Exception;
import haxe.io.Input;

class Main {
    private static var cache:Array<Array<Int>> = [
        for(i in 0...15) [
            for(j in 0...15) -1
        ]
    ];

    public static function main():Void {
        var stdin:Input = Sys.stdin();
        var t:Int = getIntFromReadLine(stdin);

        for(i in 0...t) {
            var floor:Int = getIntFromReadLine(stdin);
            var room:Int = getIntFromReadLine(stdin);

            Sys.println(recursive(floor, room));
        }

        stdin.close();
    }

    private static function getIntFromReadLine(stdin:Input):Null<Int> {
        try {
            return Std.parseInt(stdin.readLine());
        }
        catch(e:Exception) {
            return null;
        }
    }

    private static function recursive(floor:Int, room:Int):Int {
        if(floor == 0) {
            return room;
        }

        if(room == 1) {
            return 1;
        }

        if(cache[floor][room - 1] == -1) {
            cache[floor][room - 1] = recursive(floor, room - 1) + recursive(floor - 1, room);
        }

        return cache[floor][room - 1];
    }
}