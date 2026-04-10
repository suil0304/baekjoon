import haxe.io.Input;

using StringTools;

class Main {
    private static var pokemonNormalArray:Array<String> = [];
    private static var pokemonNameMap:Map<String, Int> = [];
    public static function main():Void {
        var stdin:Input = Sys.stdin();
        var datas:Array<String> = readLine(stdin).split(" ");

        var n:Int = Std.parseInt(datas[0]);
        var queryNum:Int = Std.parseInt(datas[1]);

        for(i in 0...n) {
            var str:String = readLine(stdin);
            pokemonNormalArray.push(str);
            pokemonNameMap.set(str, i);
        }

        for(i in 0...queryNum) {
            var str:String = readLine(stdin);
            var num:Null<Int> = Std.parseInt(str);
            if(num != null) {
                Sys.println(pokemonNormalArray[num - 1]);
            }
            else {
                Sys.println(pokemonNameMap.get(str) + 1);
            }
        }
    }

    private static function readLine(stdin:Input):String {
        return stdin.readLine().trim();
    }
}