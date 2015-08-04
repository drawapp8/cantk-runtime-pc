window.onload = function() {
    // * Create a stage for LWF
    window.stage = document.createElement("canvas");
    window.stage.width = 0;
    window.stage.height = 0;
    document.body.appendChild(window.stage);

    // * "LWF" has been initialized and accessible fby using LWF.
    // * Renderer should be declared 
    LWF.useCanvasRenderer();
    
    // * Get resource cache
    cache = LWF.ResourceCache.get();
        
    cache.loadLWF({
        "lwf": "menu.lwf", // *.lwf file name
        "prefix": "flash/menu.lwfdata/", // * lwf, png folder
        "stage": window.stage, // * target stage
        "onload": function(lwf) {
             window.lwf = lwf;
             window.lwf.setFrameRate(60); // Override animations frame rate. swf's frame rate can be ignored by using setFrameRate()
        }, // * function that will be called on load
    });
    
    // * Add event listener
    window.stage.addEventListener("mousemove", onmove, false);
    window.stage.addEventListener("mousedown", onpress, false);
    window.stage.addEventListener("mouseup", onrelease, false);
    window.stage.addEventListener("touchmove", onmove, false);
    window.stage.addEventListener("touchstart", onpress, false);
    window.stage.addEventListener("touchend", onrelease, false);
};


// * Main loop preparation
window.requestAnimationFrame = (function() {
    return  window.requestAnimationFrame       ||
            window.webkitRequestAnimationFrame ||
            window.mozRequestAnimationFrame    ||
            window.oRequestAnimationFrame      ||
            window.msRequestAnimationFrame     ||
            function(/* function */ callback, /* DOMElement */ element) {
              window.setTimeout(callback, 1000 / 60);
            };
})();

function main() {

    if (window.lwf != null) {
        // * Evaluate lwf and render it 
        window.lwf.exec(calc_tick());
        window.lwf.render();        
    }
    
    window.requestAnimationFrame(main); 
}
main();

// * 
var current_time, from_time
function calc_tick() {
    current_time =  Date.now() / 1000.0;
    tick = current_time - from_time;
    from_time = current_time;
    return tick
}

function onmove(e) {
    var x, y;
    x = e.clientX + document.body.scrollLeft + document.documentElement.scrollLeft - window.stage.offsetLeft;
    y = e.clientY + document.body.scrollTop + document.documentElement.scrollTop - window.stage.offsetTop;

    window.lwf.inputPoint(x, y);
}

function onpress(e) {
    var x, y;
    x = e.clientX + document.body.scrollLeft + document.documentElement.scrollLeft - window.stage.offsetLeft;
    y = e.clientY + document.body.scrollTop + document.documentElement.scrollTop - window.stage.offsetTop;

    window.lwf.inputPoint(x, y);
    window.lwf.inputPress();
}

function onrelease(e) {
    window.lwf.inputRelease();
}

