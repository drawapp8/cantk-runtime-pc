window.onload = function() {
    // * Create a stage for LWF
    var stage = document.createElement("canvas");
    stage.width = 0;
    stage.height = 0;
    document.body.appendChild(stage);

    // * "LWF" has been initialized and accessible fby using LWF.
    // * Renderer should be declared 
    LWF.useCanvasRenderer();
    
    // * Get resource cache
    cache = LWF.ResourceCache.get();
        
    cache.loadLWF({
        "lwf": "gree_logo.lwf",    // *.lwf file name
        "prefix": "lwf/flash/menu.lwfdata/", // * lwf, png folder
        "stage": stage, // * target stage
        "onload": function(lwf) {
             window.lwf = lwf;
             window.lwf.setFrameRate(60); // Override animations frame rate. swf's frame rate can be ignored by using setFrameRate()
        }, // * function that will be called on load
    });
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
    window.requestAnimationFrame(main); 

    if (window.lwf != null) {
        // * Evaluate lwf and render it 
        window.lwf.exec(calc_tick());
        window.lwf.render();
        
        window.lwf.rootMovie.gree_icon.rotation += 1.0;
        
    }
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

