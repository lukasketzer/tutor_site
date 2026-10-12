// .md files are compiled to Svelte components by mdsvex
declare module "*.md" {
    import type { ComponentType } from "svelte";
    const component: ComponentType;
    export default component;
}
